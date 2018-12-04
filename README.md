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
01|27|15|576|446|`31.8986`|[Day01.hpp](https://github.com/willkill07/AdventOfCode2018/blob/master/include/Day01.hpp)|`iterator` `numeric` `unordered_set` `vector` [`Solution.hpp`](https://github.com/willkill07/AdventOfCode2018/blob/master/include/Solution.hpp)
02|58|37|1455|1081|`13.2606`|[Day02.hpp](https://github.com/willkill07/AdventOfCode2018/blob/master/include/Day02.hpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2018/blob/master/include/Solution.hpp) [`util.hpp`](https://github.com/willkill07/AdventOfCode2018/blob/master/include/util.hpp) `algorithm` `array` `iterator` `numeric` `unordered_map` `vector`
03|57|36|1556|1255|`7.9407`|[Day03.hpp](https://github.com/willkill07/AdventOfCode2018/blob/master/include/Day03.hpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2018/blob/master/include/Solution.hpp) `algorithm` `string` `vector` `range/v3/all.hpp`
04|8|5|137|118|`0.0154`|[Day04.hpp](https://github.com/willkill07/AdventOfCode2018/blob/master/include/Day04.hpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2018/blob/master/include/Solution.hpp)
05|8|5|137|118|`0.0144`|[Day05.hpp](https://github.com/willkill07/AdventOfCode2018/blob/master/include/Day05.hpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2018/blob/master/include/Solution.hpp)
06|8|5|137|118|`0.0143`|[Day06.hpp](https://github.com/willkill07/AdventOfCode2018/blob/master/include/Day06.hpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2018/blob/master/include/Solution.hpp)
07|8|5|137|118|`0.0145`|[Day07.hpp](https://github.com/willkill07/AdventOfCode2018/blob/master/include/Day07.hpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2018/blob/master/include/Solution.hpp)
08|8|5|137|118|`0.0144`|[Day08.hpp](https://github.com/willkill07/AdventOfCode2018/blob/master/include/Day08.hpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2018/blob/master/include/Solution.hpp)
09|8|5|137|118|`0.0143`|[Day09.hpp](https://github.com/willkill07/AdventOfCode2018/blob/master/include/Day09.hpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2018/blob/master/include/Solution.hpp)
10|8|5|138|119|`0.0145`|[Day10.hpp](https://github.com/willkill07/AdventOfCode2018/blob/master/include/Day10.hpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2018/blob/master/include/Solution.hpp)
11|8|5|138|119|`0.0143`|[Day11.hpp](https://github.com/willkill07/AdventOfCode2018/blob/master/include/Day11.hpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2018/blob/master/include/Solution.hpp)
12|8|5|138|119|`0.0140`|[Day12.hpp](https://github.com/willkill07/AdventOfCode2018/blob/master/include/Day12.hpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2018/blob/master/include/Solution.hpp)
13|8|5|138|119|`0.0144`|[Day13.hpp](https://github.com/willkill07/AdventOfCode2018/blob/master/include/Day13.hpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2018/blob/master/include/Solution.hpp)
14|8|5|138|119|`0.0144`|[Day14.hpp](https://github.com/willkill07/AdventOfCode2018/blob/master/include/Day14.hpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2018/blob/master/include/Solution.hpp)
15|8|5|138|119|`0.0141`|[Day15.hpp](https://github.com/willkill07/AdventOfCode2018/blob/master/include/Day15.hpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2018/blob/master/include/Solution.hpp)
16|8|5|138|119|`0.0141`|[Day16.hpp](https://github.com/willkill07/AdventOfCode2018/blob/master/include/Day16.hpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2018/blob/master/include/Solution.hpp)
17|8|5|138|119|`0.0142`|[Day17.hpp](https://github.com/willkill07/AdventOfCode2018/blob/master/include/Day17.hpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2018/blob/master/include/Solution.hpp)
18|8|5|138|119|`0.0143`|[Day18.hpp](https://github.com/willkill07/AdventOfCode2018/blob/master/include/Day18.hpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2018/blob/master/include/Solution.hpp)
19|8|5|138|119|`0.0140`|[Day19.hpp](https://github.com/willkill07/AdventOfCode2018/blob/master/include/Day19.hpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2018/blob/master/include/Solution.hpp)
20|8|5|138|119|`0.0142`|[Day20.hpp](https://github.com/willkill07/AdventOfCode2018/blob/master/include/Day20.hpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2018/blob/master/include/Solution.hpp)
21|8|5|138|119|`0.0269`|[Day21.hpp](https://github.com/willkill07/AdventOfCode2018/blob/master/include/Day21.hpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2018/blob/master/include/Solution.hpp)
22|8|5|138|119|`0.0137`|[Day22.hpp](https://github.com/willkill07/AdventOfCode2018/blob/master/include/Day22.hpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2018/blob/master/include/Solution.hpp)
23|8|5|138|119|`0.0138`|[Day23.hpp](https://github.com/willkill07/AdventOfCode2018/blob/master/include/Day23.hpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2018/blob/master/include/Solution.hpp)
24|8|5|138|119|`0.0137`|[Day24.hpp](https://github.com/willkill07/AdventOfCode2018/blob/master/include/Day24.hpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2018/blob/master/include/Solution.hpp)
25|8|5|138|119|`0.0135`|[Day25.hpp](https://github.com/willkill07/AdventOfCode2018/blob/master/include/Day25.hpp)|[`Solution.hpp`](https://github.com/willkill07/AdventOfCode2018/blob/master/include/Solution.hpp)
**TOTAL**|**318**|**198**|**6617**|**5394**|**53.4253**| |`  Solution.hpp`&nbsp;<sup>**`25`**</sup> ` vector`&nbsp;<sup>**`3`**</sup> ` numeric`&nbsp;<sup>**`2`**</sup> ` algorithm`&nbsp;<sup>**`2`**</sup> ` iterator`&nbsp;<sup>**`2`**</sup> ` util.hpp`&nbsp;<sup>**`1`**</sup> ` array`&nbsp;<sup>**`1`**</sup> ` unordered_set`&nbsp;<sup>**`1`**</sup> ` unordered_map`&nbsp;<sup>**`1`**</sup> ` range/v3/all.hpp`&nbsp;<sup>**`1`**</sup> ` string`&nbsp;<sup>**`1`**</sup> ` `
