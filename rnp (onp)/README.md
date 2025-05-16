# ONP Converter – Infix to Postfix (Reverse Polish Notation)

A simple implementation of the Shunting Yard algorithm in C++.

## Features
- Handles `+`, `-`, `*`, `/`, `^` operators
- Proper operator precedence and associativity (`^` is right-associative)
- Supports parentheses
- Outputs expressions in Reverse Polish Notation (postfix)

## Example
**Input**:  
```
3 + 4 * 2 / (1 - 5) ^ 2
```

**Output (ONP)**:  
```
3 4 2 * 1 5 - 2 ^ / +
```

## Usage
```bash
g++ onp.cpp -o onp
./onp
```

## License
MIT – use freely, share the knowledge ;)
