 * node.hpp
```cpp
Node
{
  state
  path
}
```
 * default_cost_func.hpp
```cpp
DefaultCostFunc (node) -> node.path.size() 
```
 * priority_queue.hpp
```cpp
 Using pseudocodes from "Introduction to Algorithms 3rd edition" aka C.L.R.S.
```
 * time_record.hpp
```cpp
//a timer implemented with RAII style
TimeRecord
{
  constructor(reference)
    start timer
  
  destructor()
    stop timer
    write time duration to outside by reference 
}
```
 * heuristic_func.hpp
```cpp
ManhattanDistance (curr, goal)
  ret = 0
  for i = 0 to length(goal) - 1
    if ('0' != curr[i])
      digit = curr[i] - '0'
      ret += abs(i / 3 - digit / 3) + abs(i % 3 - digit % 3)
  return ret
  
MisplacedTiles (curr, goal)
  count = 0
  for i = 0 to length(goal) - 1
    if (curr[i] != goal[i]) 
       count = count + 1
  return count
```
 
