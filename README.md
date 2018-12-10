# Advent of Code - 2018

All implementations are written in C++, mostly adhering to C++17/C++20 guidelines.

## Prerequisites

* clang (>= 5.0)
* libc++ (>= 5.0)
* CMake (>= 3.11)
* macOS or Linux (only two systems I've tested on)

## Compiling

* Your standard cmake-enabled project

## Running

* Invoke `./Advent` to execute all the days
* To run a specific day, invoke `./Advent -f <dayXX>`
* To run a specific part, invoke `./Advent -p <1,2>`
* To see more detailed help, consult `./Advent --help`

## Metrics

* Lines: Number of lines given by `wc`
* Code: `Lines` - `(# preprocessor lines)` - `(lines with no alphanumeric chars)`
* Bytes: Number of total characters
* Chars: Number of non-whitespace characters
* Time: Time in milliseconds to execute each part independently (separate runs)
* Source: link to implementation
* Headers: C++ includes used for solution

## Leaderboard Highlights:

Day | Part 1 | Part 2
:--:|:-------|:------
1   | 52     | 217 

## Detailed Information

 Day | Lines | Code | Bytes | Chars | Time (ms) | Source | Headers
:---:|:-----:|:----:|:-----:|:-----:| ---------:|:------:|:-------
01|30|16|727|606|`28.7253`|[Day01.cpp](https://github.com/willkill07/AdventOfCode2018/blob/master/src/Day01.cpp)|`iterator` `unordered_set` `vector` `range/v3/numeric.hpp` `range/v3/view/cycle.hpp` [`Solution.hpp`](https://github.com/willkill07/AdventOfCode2018/blob/master/include/Solution.hpp)
02|62|40|1611|1225|`14.8138`|[Day02.cpp](https://github.com/willkill07/AdventOfCode2018/blob/master/src/Day02.cpp)|`algorithm` `array` `iterator` `numeric` `unordered_map` `vector` [`Solution.hpp`](https://github.com/willkill07/AdventOfCode2018/blob/master/include/Solution.hpp) [`util.hpp`](https://github.com/willkill07/AdventOfCode2018/blob/master/include/util.hpp)
03|71|39|2024|1693|`9.7506`|[Day03.cpp](https://github.com/willkill07/AdventOfCode2018/blob/master/src/Day03.cpp)|`algorithm` `string` `vector` `range/v3/algorithm.hpp` `range/v3/getlines.hpp` `range/v3/numeric.hpp` `range/v3/view/cartesian_product.hpp` `range/v3/view/filter.hpp` `range/v3/view/iota.hpp` `range/v3/view/join.hpp` `range/v3/view/take_while.hpp` `range/v3/view/view.hpp` [`Solution.hpp`](https://github.com/willkill07/AdventOfCode2018/blob/master/include/Solution.hpp)
04|52|30|1454|1153|`3.1063`|[Day04.cpp](https://github.com/willkill07/AdventOfCode2018/blob/master/src/Day04.cpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2018/blob/master/include/Solution.hpp) `unordered_map` `vector` `range/v3/algorithm.hpp` `range/v3/getlines.hpp` `range/v3/numeric.hpp` `range/v3/view/slice.hpp`
05|49|29|1232|1012|`22.6273`|[Day05.cpp](https://github.com/willkill07/AdventOfCode2018/blob/master/src/Day05.cpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2018/blob/master/include/Solution.hpp) `iterator` `vector` `range/v3/algorithm/min.hpp` `range/v3/view/indices.hpp` `range/v3/view/remove_if.hpp` `range/v3/view/repeat.hpp` `range/v3/view/transform.hpp` `range/v3/view/zip_with.hpp`
06|120|77|3059|2236|`47.9081`|[Day06.cpp](https://github.com/willkill07/AdventOfCode2018/blob/master/src/Day06.cpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2018/blob/master/include/Solution.hpp) `limits` `iterator` `set` `vector` `range/v3/algorithm/min.hpp` `range/v3/view/indices.hpp` `range/v3/view/transform.hpp` `range/v3/view/zip.hpp`
07|73|45|1767|1225|`3.1507`|[Day07.cpp](https://github.com/willkill07/AdventOfCode2018/blob/master/src/Day07.cpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2018/blob/master/include/Solution.hpp) `map` `set` `vector` `range/v3/algorithm/max.hpp` `range/v3/view/filter.hpp` `range/v3/view/map.hpp` `range/v3/getlines.hpp`
08|59|34|1376|1087|`12.7941`|[Day08.cpp](https://github.com/willkill07/AdventOfCode2018/blob/master/src/Day08.cpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2018/blob/master/include/Solution.hpp) `iterator` `vector` `range/v3/numeric.hpp` `range/v3/view/transform.hpp` `range/v3/view/filter.hpp`
09|89|59|1778|1313|`1238.1698`|[Day09.cpp](https://github.com/willkill07/AdventOfCode2018/blob/master/src/Day09.cpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2018/blob/master/include/Solution.hpp) `iterator` `range/v3/algorithm/max.hpp` `vector`
10|114|76|4134|3484|`0.5392`|[Day10.cpp](https://github.com/willkill07/AdventOfCode2018/blob/master/src/Day10.cpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2018/blob/master/include/Solution.hpp) `limits` `set` `vector` `unordered_map` `range/v3/algorithm.hpp` `range/v3/getlines.hpp` `range/v3/numeric.hpp` `range/v3/view/chunk.hpp` `range/v3/view/indices.hpp` `range/v3/view/repeat.hpp` `range/v3/view/transform.hpp` `range/v3/view/zip.hpp`
11|12|8|285|254|`0.0176`|[Day11.cpp](https://github.com/willkill07/AdventOfCode2018/blob/master/src/Day11.cpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2018/blob/master/include/Solution.hpp)
12|12|8|285|254|`0.0189`|[Day12.cpp](https://github.com/willkill07/AdventOfCode2018/blob/master/src/Day12.cpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2018/blob/master/include/Solution.hpp)
13|12|8|285|254|`0.0172`|[Day13.cpp](https://github.com/willkill07/AdventOfCode2018/blob/master/src/Day13.cpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2018/blob/master/include/Solution.hpp)
14|12|8|285|254|`0.0161`|[Day14.cpp](https://github.com/willkill07/AdventOfCode2018/blob/master/src/Day14.cpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2018/blob/master/include/Solution.hpp)
15|12|8|285|254|`0.0162`|[Day15.cpp](https://github.com/willkill07/AdventOfCode2018/blob/master/src/Day15.cpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2018/blob/master/include/Solution.hpp)
16|12|8|285|254|`0.0160`|[Day16.cpp](https://github.com/willkill07/AdventOfCode2018/blob/master/src/Day16.cpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2018/blob/master/include/Solution.hpp)
17|12|8|285|254|`0.0161`|[Day17.cpp](https://github.com/willkill07/AdventOfCode2018/blob/master/src/Day17.cpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2018/blob/master/include/Solution.hpp)
18|12|8|285|254|`0.0163`|[Day18.cpp](https://github.com/willkill07/AdventOfCode2018/blob/master/src/Day18.cpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2018/blob/master/include/Solution.hpp)
19|12|8|285|254|`0.0164`|[Day19.cpp](https://github.com/willkill07/AdventOfCode2018/blob/master/src/Day19.cpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2018/blob/master/include/Solution.hpp)
20|12|8|285|254|`0.0159`|[Day20.cpp](https://github.com/willkill07/AdventOfCode2018/blob/master/src/Day20.cpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2018/blob/master/include/Solution.hpp)
21|12|8|285|254|`1.3397`|[Day21.cpp](https://github.com/willkill07/AdventOfCode2018/blob/master/src/Day21.cpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2018/blob/master/include/Solution.hpp)
22|12|8|285|254|`0.0319`|[Day22.cpp](https://github.com/willkill07/AdventOfCode2018/blob/master/src/Day22.cpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2018/blob/master/include/Solution.hpp)
23|12|8|285|254|`0.0268`|[Day23.cpp](https://github.com/willkill07/AdventOfCode2018/blob/master/src/Day23.cpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2018/blob/master/include/Solution.hpp)
24|12|8|285|254|`0.0280`|[Day24.cpp](https://github.com/willkill07/AdventOfCode2018/blob/master/src/Day24.cpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2018/blob/master/include/Solution.hpp)
25|12|8|285|254|`0.0207`|[Day25.cpp](https://github.com/willkill07/AdventOfCode2018/blob/master/src/Day25.cpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2018/blob/master/include/Solution.hpp)
**TOTAL**|**899**|**565**|**23437**|**18844**|**1383.2**| |`  Solution.hpp`&nbsp;<sup>**`25`**</sup> ` vector`&nbsp;<sup>**`10`**</sup> ` iterator`&nbsp;<sup>**`6`**</sup> ` range/v3/numeric.hpp`&nbsp;<sup>**`5`**</sup> ` range/v3/getlines.hpp`&nbsp;<sup>**`4`**</sup> ` range/v3/view/transform.hpp`&nbsp;<sup>**`4`**</sup> ` range/v3/view/indices.hpp`&nbsp;<sup>**`3`**</sup> ` unordered_map`&nbsp;<sup>**`3`**</sup> ` range/v3/view/filter.hpp`&nbsp;<sup>**`3`**</sup> ` set`&nbsp;<sup>**`3`**</sup> ` range/v3/algorithm.hpp`&nbsp;<sup>**`3`**</sup> ` limits`&nbsp;<sup>**`2`**</sup> ` range/v3/view/zip.hpp`&nbsp;<sup>**`2`**</sup> ` range/v3/algorithm/min.hpp`&nbsp;<sup>**`2`**</sup> ` range/v3/view/repeat.hpp`&nbsp;<sup>**`2`**</sup> ` algorithm`&nbsp;<sup>**`2`**</sup> ` range/v3/algorithm/max.hpp`&nbsp;<sup>**`2`**</sup> ` util.hpp`&nbsp;<sup>**`1`**</sup> ` range/v3/view/cartesian_product.hpp`&nbsp;<sup>**`1`**</sup> ` array`&nbsp;<sup>**`1`**</sup> ` range/v3/view/map.hpp`&nbsp;<sup>**`1`**</sup> ` range/v3/view/join.hpp`&nbsp;<sup>**`1`**</sup> ` numeric`&nbsp;<sup>**`1`**</sup> ` range/v3/view/remove_if.hpp`&nbsp;<sup>**`1`**</sup> ` range/v3/view/chunk.hpp`&nbsp;<sup>**`1`**</sup> ` range/v3/view/take_while.hpp`&nbsp;<sup>**`1`**</sup> ` unordered_set`&nbsp;<sup>**`1`**</sup> ` range/v3/view/zip_with.hpp`&nbsp;<sup>**`1`**</sup> ` range/v3/view/view.hpp`&nbsp;<sup>**`1`**</sup> ` range/v3/view/cycle.hpp`&nbsp;<sup>**`1`**</sup> ` range/v3/view/slice.hpp`&nbsp;<sup>**`1`**</sup> ` range/v3/view/iota.hpp`&nbsp;<sup>**`1`**</sup> ` string`&nbsp;<sup>**`1`**</sup> ` map`&nbsp;<sup>**`1`**</sup> ` `
