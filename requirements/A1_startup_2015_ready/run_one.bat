cls
@echo off
@echo ==============================================================================================================
@echo                                               SEARCH ALGORITHMS 
@echo ==============================================================================================================

@echo (1) PDS_Visited_List
@echo (2) bestFirstSearch_Visited_List
@echo (3) uniformCost_Exp_List
@echo (4) aStar_Misplaced
@echo (5) aStar_Manhattan
@echo (6) aStar_Exp_List_Misplaced
@echo (7) aStar_Exp_List_Manhattan

set /p selection="Select Algorithm: "
@echo You picked Algorithm # %selection%


REM INIT_STATE #1: 042158367, GOAL_STATE: 012345678 
REM INIT_STATE #2: 168342750, GOAL_STATE: 012345678
REM INIT_STATE #3: 481302675, GOAL_STATE: 012345678
REM INIT_STATE #4: 876543210, GOAL_STATE: 012345678
REM INIT_STATE #5: 123804765, GOAL_STATE: 012345678

if %selection% == 1 (
    main.exe "single_run" "PDS_Visited_List" "876543210" "012345678"
) else if %selection% == 2 (
    main.exe "single_run" "bestFirstSearch_Visited_List" "876543210" "012345678"
) else if %selection% == 3 (
    main.exe "single_run" "uniformCost_Exp_List" "876543210" "012345678"
) else if %selection% == 4 (
    main.exe "single_run" "aStar_Misplaced" "876543210" "012345678"
) else if %selection% == 5 (
    main.exe "single_run" "aStar_Manhattan" "876543210" "012345678"
) else if %selection% == 6 (
    main.exe "single_run" "aStar_Exp_List_Misplaced" "876543210" "012345678"
) else if %selection% == 7 (
    main.exe "single_run" "aStar_Exp_List_Manhattan" "876543210" "012345678"
)


@echo ==============================================================================================================
@echo nothing follows.

REM "and so on..."