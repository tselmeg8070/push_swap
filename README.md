# Push swap

42 school project. Sort "a" stack using another stack and with limited number of commands.

## Approach

- Convert arguments to structure and check for an invalid data
- Sort stack using quicksort algorithm and put instructions to another stack to use it for later
- Collide instructions using result of the quicksort algorithm. Example sa, sb -> ss
- Print the final result

## Installation and run

Push swap uses c programming language.

```sh
make
```

To run

```sh
./push_swap "5 4 3 2 1"
```

## Result



| Case in length of numbers | Result in number of instructions |
| ------ | ------ |
| 3 | <3 |
| 5 | <12 |
| 100 | <750 |
| 500 | <5500 |

