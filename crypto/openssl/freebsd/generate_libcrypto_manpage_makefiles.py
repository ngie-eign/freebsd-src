#!/usr/bin/env python
"""Parse manpages provided on the command line and output Makefile data for OpenSSL."""

from __future__ import annotations

import argparse
import collections
import pathlib
import re
import sys
import typing

if typing.TYPE_CHECKING:
    import io


# ruff: noqa: S101, T201

SH_RE = re.compile(".Sh (.+)")
NAME_LINE_RE = re.compile(r".Nm\s+(.+)\s*,?")
NAME_RE = re.compile(r"(\w\S+)")
NAME_SEP_RE = re.compile(r",\s*")

MANPAGES = []
MANPAGE_LINKS = collections.defaultdict(list)


def parse_manpage(manpage_fobj: io.TextIOBase) -> None:
    """Parse a manpage for a name/links."""
    aliases = []

    collect_names = False
    manpage_p = pathlib.Path(manpage_fobj.name)

    manpage_filename = manpage_p.name
    manpage_name = manpage_p.stem
    manpage_section = manpage_p.suffix

    for line in manpage_fobj:
        if (sh_res := SH_RE.match(line)) is not None:
            collect_names = sh_res.group(1) == "NAME"
        elif collect_names and (line_res := NAME_LINE_RE.match(line)) is not None:
            line_trimmed = NAME_SEP_RE.sub("", line_res.group(1))
            for token in NAME_SEP_RE.split(line_trimmed):
                name_res = NAME_RE.match(token)
                assert name_res is not None, (
                    f"token={token} does not contain valid name. manpage={manpage_p.name}"
                )
                assert len(name_res.groups()) == 1, (
                    f"line={line} matched multiple times unexpectedly."
                )
                if manpage_name != name_res.group(1):
                    aliases.extend(NAME_RE.findall(token))
                # print(
                #    f"alias={alias!r} -> manpage_name={manpage_name!r}, "
                #    f"token={token!r}",
                #    file=sys.stderr,
                # )

    MANPAGES.append(manpage_filename)
    MANPAGE_LINKS[manpage_filename] = [
        f"{manpage_name}{manpage_section} {alias}{manpage_section}"
        for alias in aliases
    ]


def main(argv: list[str] | None = None) -> int:
    """Eponymous main."""
    argparser = argparse.ArgumentParser()
    argparser.add_argument(
        "manpages",
        metavar="MANPAGE",
        nargs="+",
        type=argparse.FileType("r"),
    )
    args = argparser.parse_args(argv)

    for manpage_fobj in args.manpages:
        with manpage_fobj:
            parse_manpage(manpage_fobj)

        for manpage in sorted(MANPAGES):
            print(f"MAN+= {manpage}")
            for manpage_link in sorted(MANPAGE_LINKS[manpage]):
                print(f"MLINKS+= {manpage_link}")

    return 0


if __name__ == "__main__":
    sys.exit(main())
