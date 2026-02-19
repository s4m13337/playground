package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	fmt.Println("User inputs in Go")
	fmt.Println("Give a rating between 1 and 10")
	reader := bufio.NewReader(os.Stdin)

	input, err := reader.ReadString('\n')
	if err != nil {
		fmt.Println("Error reading input")
		os.Exit(-1)
	}

	/*
		The input from the standard input contains the \n
		It needs to be removed before converting it into a float
		This is done using the TrimSpace method of strings
	*/
	rating, err := strconv.ParseFloat(strings.TrimSpace(input), 64)
	if err != nil {
		fmt.Println("Error converting input to float")
	}

	fmt.Println("Thank you for the rating of", rating+1.667)
}
