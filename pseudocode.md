 * `node.hpp`
```f#
let Node be: 
    { state, path } 
as a struct
```
 * `default_cost_func.hpp`
```f#
let DefaultCostFunc (node) be: 
    node.path.size() 
as a functor
```
 * `priority_queue.hpp`
```f#
 Using pseudocodes from "Chapter 6, Introduction to Algorithms 3rd edition" aka C.L.R.S.
```
 * `time_record.hpp`
```f#
//a timer implemented with RAII style
let TimeRecord be:
{
    let constructor(reference) be:
        start timer
  
    let destructor() be:
        stop timer and write time duration to outside by reference 
}
as a class

```
 * `heuristic_func.hpp`
```f#
let ManhattanDistance (curr, goal) be :
    ret = 0
    for i = 0 to length(goal) - 1
        if ('0' != curr[i])
        digit = curr[i] - '0'
        ret += abs(i / 3 - digit / 3) + abs(i % 3 - digit % 3)
    return ret
as a functor
  
let MisplacedTiles (curr, goal) be :
    count = 0
    for i = 0 to length(goal) - 1
        if (curr[i] != goal[i]) 
        count = count + 1
    return count
as a functor
```
 * `function_dictionary.hpp`
```f#
//this class implmented a function dictionary mapping each position of `0` to its possible children state.
let FunctionDictionary be:
{
    let constructor() be:
        fill_dictionary()
    
    let fill_dictionary() be:
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
    as a method
}
as a class
```
 * `progressive_deepening_search_with_visited_list.hpp`
```f#
let class PDSWithVList be:
{
    let constructor(source, goal) be:
        record time
        search(source, goal)
 
    let search(source, goal) be:
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
    as a method
}
```
 * `best_first_search_with_visited_list.hpp`
```cpp
let BestFSWithVList be:
{
    //this functor is going to be passed to priority queue for comparison
    let Greater(lhs, rhs) be:
        define h as an object of HeuristicFunc
        return h(lhs to goal) > h(rhs to goal)
    as a functor 
    
    let constructor(source, goal) be:
        record time
        search(source, goal)
    
    let search be:
        q.push(Node(source))
        while q is not empty
            curr = q.pop()
            visited_list.insert(state(curr))
            if goal == state(curr)
                final_path = path(curr)
                return
            for lamda : make_child in function_dictionary.at(state(curr).find('0'))
                child = make_child(curr)
                if visited_list doesn't contain state(child) 
                    q.push(child)
    as a method
}
as a class
```
