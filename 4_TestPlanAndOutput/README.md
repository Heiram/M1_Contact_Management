# TEST PLAN and Corresponding Output
## High Level Test Plan
| Test ID | Description | Exp.i/p | Exp.o/p | Actual o/p | Type of Test |
| --------|:------------|:--------|:--------|:-----------|:-------------|
| H_01 | check if the welcoming page is displayed properly | program execution | formatted welcome page | formatted welcome page | Requirement |
| H_02 | check if the contact details entered correctly | proper function execution | formatted detail page | formatted detail page | Requirement |
| H_03 | check if the contact list displayed properly | proper function execution | formatted list page | formatted list page | Requirement |
| H_04 | check if the contact list searched  correctly | proper function execution | formatted search page | formatted search page | Requirement |
| H_05 | check if the menu is displayed properly | program execution | formatted menu page | formatted menu page | Requirement |
## Low Level Test Plan 
| Test ID | Description | Exp.i/p | Exp.o/p | Actual o/p | Type of Test |
| --------|:------------|:--------|:--------|:-----------|:-------------|
| L_01 | verify welcoming page | welcome page | success->menu; failure->exit | success->menu; failure->exit | Scenario |
| L_02 | add details to the contacts | details of individual | details added successfully | details added successfully | Technical |
| L_03 | display list | - | if entry is present->display them; else display "empty file" | if entry is present->display them; else display "empty file" | Technical | 
| L_04 | search contact list | name of the individual | name present->search; name absent->not found | name present->search; name absent->not found | Technical |
| L_05 | return menu page | menu page | success->menu; failure->exit | success->menu; failure->exit | Scenario |