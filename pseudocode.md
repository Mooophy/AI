 * Node.hpp
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
 
