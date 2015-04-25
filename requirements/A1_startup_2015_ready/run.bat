cls
@echo off
@echo ==============================================================================================================
@echo                                               SEARCH ALGORITHMS 
@echo ==============================================================================================================
@echo submitted by:   Name, ID number
@echo                 Name, ID number
@echo                 Name, ID number
@echo ==============================================================================================================
@echo EXPERIMENT (1)
@echo ==============================================================================================================
@echo INIT_STATE_#1:  042158367     GOAL STATE: 012345678
@echo ==============================================================================================================
@echo  ALGORITHM		  PATH_LENGTH	STATE_EXPANSIONS    MAX_QLENGTH	 RUNNING_TIME 
@echo ==============================================================================================================

main.exe "batch_run" "PDS_Visited_List" 					"042158367" "012345678"
main.exe "batch_run" "bestFirstSearch_Visited_List" 	"042158367" "012345678"
main.exe "batch_run" "uniformCost_Exp_List" 				"042158367" "012345678"
main.exe "batch_run" "aStar_Misplaced" 					"042158367" "012345678"
main.exe "batch_run" "aStar_Manhattan" 					"042158367" "012345678"
main.exe "batch_run" "aStar_Exp_List_Misplaced"      	"042158367" "012345678"
main.exe "batch_run" "aStar_Exp_List_Manhattan" 		"042158367" "012345678"


@echo ==============================================================================================================
@echo EXPERIMENT (2)
@echo ==============================================================================================================
@echo INIT_STATE_#2: 168342750     GOAL STATE: 012345678
@echo ==============================================================================================================
@echo  ALGORITHM		  PATH_LENGTH	STATE_EXPANSIONS    MAX_QLENGTH	 RUNNING_TIME 
@echo ==============================================================================================================
main.exe "batch_run" "PDS_Visited_List" 					"168342750" "012345678"
main.exe "batch_run" "bestFirstSearch_Visited_List" 	"168342750" "012345678"
main.exe "batch_run" "uniformCost_Exp_List" 				"168342750" "012345678"
main.exe "batch_run" "aStar_Misplaced" 					"168342750" "012345678"
main.exe "batch_run" "aStar_Manhattan" 					"168342750" "012345678"
main.exe "batch_run" "aStar_Exp_List_Misplaced"      	"168342750" "012345678"
main.exe "batch_run" "aStar_Exp_List_Manhattan" 		"168342750" "012345678"

@echo ==============================================================================================================
@echo EXPERIMENT (3)
@echo ==============================================================================================================
@echo INIT_STATE_#3: 481302675     GOAL STATE: 012345678
@echo ==============================================================================================================
@echo  ALGORITHM		  PATH_LENGTH	STATE_EXPANSIONS    MAX_QLENGTH	 RUNNING_TIME 
@echo ==============================================================================================================
main.exe "batch_run" "PDS_Visited_List" 					"481302675" "012345678"
main.exe "batch_run" "bestFirstSearch_Visited_List" 	"481302675" "012345678"
main.exe "batch_run" "uniformCost_Exp_List" 				"481302675" "012345678"
main.exe "batch_run" "aStar_Misplaced" 					"481302675" "012345678"
main.exe "batch_run" "aStar_Manhattan" 					"481302675" "012345678"
main.exe "batch_run" "aStar_Exp_List_Misplaced"      	"481302675" "012345678"
main.exe "batch_run" "aStar_Exp_List_Manhattan" 		"481302675" "012345678"


@echo ==============================================================================================================
@echo EXPERIMENT (4)
@echo ==============================================================================================================
@echo INIT_STATE_#4: 876543210     GOAL STATE: 012345678
@echo ==============================================================================================================
@echo  ALGORITHM		  PATH_LENGTH	STATE_EXPANSIONS    MAX_QLENGTH	 RUNNING_TIME 
@echo ==============================================================================================================
main.exe "batch_run" "PDS_Visited_List" 					"876543210" "012345678"
main.exe "batch_run" "bestFirstSearch_Visited_List" 	"876543210" "012345678"
main.exe "batch_run" "uniformCost_Exp_List" 				"876543210" "012345678"
main.exe "batch_run" "aStar_Misplaced" 					"876543210" "012345678"
main.exe "batch_run" "aStar_Manhattan" 					"876543210" "012345678"
main.exe "batch_run" "aStar_Exp_List_Misplaced"      	"876543210" "012345678"
main.exe "batch_run" "aStar_Exp_List_Manhattan" 		"876543210" "012345678"

@echo ==============================================================================================================
@echo EXPERIMENT (5)
@echo ==============================================================================================================
@echo INIT_STATE_#5: 123804765     GOAL STATE: 012345678
@echo ==============================================================================================================
@echo  ALGORITHM		  PATH_LENGTH	STATE_EXPANSIONS    MAX_QLENGTH	 RUNNING_TIME 
@echo ==============================================================================================================
main.exe "batch_run" "PDS_Visited_List" 					"123804765" "012345678"
main.exe "batch_run" "bestFirstSearch_Visited_List" 	"123804765" "012345678"
main.exe "batch_run" "uniformCost_Exp_List" 				"123804765" "012345678"
main.exe "batch_run" "aStar_Misplaced" 					"123804765" "012345678"
main.exe "batch_run" "aStar_Manhattan" 					"123804765" "012345678"
main.exe "batch_run" "aStar_Exp_List_Misplaced"      	"123804765" "012345678"
main.exe "batch_run" "aStar_Exp_List_Manhattan" 		"123804765" "012345678"
@echo nothing follows.

