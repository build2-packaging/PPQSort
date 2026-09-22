# PPQSort - Parallel quicksort C++ library

This is a `build2` package repository for
[`PPQSort`](https://github.com/GabTux/PPQSort), a header-only parallel
quicksort implementation written using only C++20 features, with no
third-party dependencies.

This file contains setup instructions and other details that are more
appropriate for development rather than consumption. If you want to use
`PPQSort` in your `build2`-based project, then instead see the accompanying
[`libppqsort/PACKAGE-README.md`](libppqsort/PACKAGE-README.md) file.

The development setup for `PPQSort` uses the standard `bdep`-based workflow.
For example:

```
git clone --recurse-submodules https://github.com/build2-packaging/PPQSort.git
cd PPQSort

bdep init -C @gcc cc config.cxx=g++
bdep update
bdep test
```
