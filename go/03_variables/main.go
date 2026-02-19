package main

import "fmt"

const G float32 = 6.67e-11

var g float32 = 9.8

func main() {
	// As seen in 02, variables are declared with var keyword
	// When var is used, it is a recommended practice to annotate the type
	var pi float32
	pi = 3.14
	fmt.Println("Value of pi is", pi)

	// Values can be assigned in a singe line too
	var stp float32 = 25.0
	fmt.Println("Standard Temperature & Pressure is", stp)

	// The var keyword can be avoided by using the walrus operator
	// The walrus operator declares and initializes the variable in a single line
	// This is the preferred method to create variables in Go
	// When the walrus operator is used, the lexer infers the type of the variable
	root_2 := 1.414
	fmt.Println("Square root of 2 is", root_2)

	// Mutiple variables can be assigned in a single line
	a, b := 3, 7.133
	fmt.Println("a is", a, "b is", b)

	// ! Constants and global variables cannot be defined using the walrus operator
	fmt.Println("The gravitational constant is", G)
	fmt.Println("Acceleration due to gravity", g)
}
