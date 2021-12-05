# MultiTool
A multi-Platform multi-Functional Tool writte in C++

# Features:

| Feature | Usage |
| ------- | ----- |
 help | Show help output | 
 [Pw](#pw)   | Show a random password | 
 [Num](#num) | Show a pseudorandom number | 
 [Name](#name) | Show a random username | 
 [d2h](#d2h---base64dec) | Convert decimal to hex |  
 [d2b](#d2h---base64dec) | Convert decimal to binary | 
 [d2c](#d2h---base64dec) | Convert decimal to character | 
 [h2d](#d2h---base64dec) | Convert hex to decimal | 
 [h2b](#d2h---base64dec) | Convert hex to binary | 
 [h2s](#d2h---base64dec) | Convert hex to string | 
 [b2d](#d2h---base64dec) | Convert binary to decimal | 
 [b2h](#d2h---base64dec) | Convert binary to hex | 
 [b2c](#d2h---base64dec) | Convert binary to character | 
 [s2h](#d2h---base64dec) | Convert string to hex | 
 [s2b](#d2h---base64dec) | Convert string to binary | 
 [base64Enc](#d2h---base64dec) | Encode a base64 string | 
 [base64Dec](#d2h---base64dec) | Decode a base64 string | 

# Options

## Pw
| Option | Usage |
| -- | -- |
 'l' | use lower characters | 
 'u' | use upper characters | 
 'n' | use numbers | 
 's' | use special characters | 
 'rx' | create x Passwords | 

Usage: 
    ```mt Pw [options] [length]```

| Example | howto |
| -- | -- |
 1 password with the length of 20 | ```mt Pw``` | 
 12 passwords with the length of 50 | ```mt Pw r12 50``` | 
 2 number-only passwords with the length of 4 | ```mt Pw nr2 4``` | 

## Num
Usage:
    ```mt Num [min] [max]```

| Example | howto |
| -- | -- |
 Number between 1 and 10 | ```mt Num``` | 
 Number between 1 and 100 | ```mt Num 100``` | 
 Number between -10 and 0 | ```mt Num -10 0``` | 

## Name
| Option | Usage |
| -- | -- |
 'l' | only lowercase name |
 'u' | only uppercase name |
 'n' | first character of each word is uppercase (default) |
 'ry'| create y usernames |
 'my' | set minimum length to y |
 'xy' | set maximum length to y |

Usage:
    ```mt Name [options] [path]```

| Example | howto |
| -- | -- |
 Name with a minimum length of 3 and maximum length of 20 |```mt Name```
 4 uppercase names with a minimum length of 20 and maximum length of 50 | ```mt Name ur4m20x50``` |
 2 names using 'firstList.txt' and 'secondList.txt' saved at 'C:\\' | ```mt Name r2 "C:\"``` |

## d2h - base64Dec
Usage: 
    ```mt d2h [input]```

Examples:
| Example | howto |
| -- | -- |
 Convert 5 to hex | ```mt d2h 5``` |
 Decode base64 string | ```mt base64Dec aHR0cHM6Ly9naXRodWIuY29tL2phbHVwYWph``` |
