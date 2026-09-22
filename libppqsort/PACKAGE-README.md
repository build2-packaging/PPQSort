# libppqsort - Parallel quicksort C++ library

This is a `build2` package for the [`PPQSort`](https://github.com/GabTux/PPQSort)
C++ library. It provides an efficient implementation of a parallel
quicksort algorithm, written using only C++20 features without third-party
libraries. It draws inspiration from pdqsort, BlockQuicksort, and cpp11sort.
It exposes a `std::sort`-like API driven by `ppqsort::execution` policies
(`seq`, `par`, and branchless-forcing variants) and, by default, uses
`std::thread` for parallelism. Compiling the consumer with OpenMP enabled
(which defines `_OPENMP`) makes the parallel policies use an OpenMP-based
backend instead, unless `FORCE_CPP` is defined.


## Usage

To start using `libppqsort` in your project, add the following `depends`
value to your `manifest`, adjusting the version constraint as appropriate:

```
depends: libppqsort ^1.0.6
```

Then import the library in your `buildfile`:

```
import libs = libppqsort%lib{ppqsort}
```


## Importable targets

This package provides the following importable targets:

```
lib{ppqsort}
```

A single header-only (binless) library target. Include `<ppqsort.h>` and
call, for example, `ppqsort::sort(ppqsort::execution::par, v.begin(), v.end())`.


## Configuration variables

This package has no configuration variables.
