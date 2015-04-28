 * `node.hpp`
```cpp
Node
{ state, path }
```
 * `default_cost_func.hpp`
```cpp
let functor DefaultCostFunc (node) = node.path.size() 
```
 * `priority_queue.hpp`
```cpp
 Using pseudocodes from "Introduction to Algorithms 3rd edition" aka C.L.R.S.
```
 * `time_record.hpp`
```cpp
//a timer implemented with RAII style
TimeRecord
{
    constructor(reference)
        start timer
  
    destructor()
        stop timer and write time duration to outside by reference 
}
```
 * `heuristic_func.hpp`
```cpp
let functor ManhattanDistance (curr, goal) be :
    ret = 0
    for i = 0 to length(goal) - 1
        if ('0' != curr[i])
        digit = curr[i] - '0'
        ret += abs(i / 3 - digit / 3) + abs(i % 3 - digit % 3)
    return ret
  
let functor MisplacedTiles (curr, goal) be :
    count = 0
    for i = 0 to length(goal) - 1
        if (curr[i] != goal[i]) 
        count = count + 1
    return count
```
 * `function_dictionary.hpp`
```cpp
//this class implmented a function dictionary mapping each position of `0` to its possible children state.
FunctionDictionary 
{
    constructor()
        fill_dictionary()
    
    fill_dictionary()
        let lambda u(position) = position - 3
        let lambda d(position) = position + 3
        let lambda l(position) = position - 1
        let lambda r(position) = position + 1
    
        let lambda make_child(parent, move_lambda, direction) be:
            pos = state(parent).find('0')
            stt = state(parent)
            swap(stt[pos], stt[move_lambda(pos)])
            return Node(stt, path(parent) + direction)
    
        let lambda up(parent) = make_child(parent, u, 'U')
        let lambda dw(parent) = make_child(parent, d, 'D')
        let lambda lt(parent) = make_child(parent, l, 'L')
        let lambda rt(parent) = make_child(parent, r, 'R')
    
        //fill possible lambda into dictionary
        this[0] = LambdaList{ dw, rt }
        this[2] = LambdaList{ dw, lt }
        this[6] = LambdaList{ up, rt }
        this[8] = LambdaList{ up, lt }
        this[1] = LambdaList{ dw, lt, rt }
        this[3] = LambdaList{ up, dw, rt }
        this[5] = LambdaList{ up, dw, lt };
        this[7] = LambdaList{ up, lt, rt };
        this[4] = LambdaList{ up, dw, lt, rt };
}
```
 * `progressive_deepening_search_with_visited_list.hpp`
```cpp

PDSWithVList
{
    constructor()
        record time
        search(source, goal)
 
    search(source, goal)
        max_depth = 0
        while true
            reset q and visited_list
            q.push(Node(source))
            while q is not empty
                curr = q.pop()
                visited_list.insert(curr)
                if goal == state(curr)
                    final_path = path(curr), return
            if length(path(curr)) < max_depth
                for lamda : make_child in function_dictionary.at(state(curr).find('0'))
                    child = make_child(curr)
                    if visited_list doesn't contain state(child)
                    q.push(child)
}
```
 * `best_first_search_with_visited_list.hpp`
```cpp

```
