package main

import "fmt"

func main() {
	fmt.Println("Go Types!")

	// Boolean types - true or false
	var userQ bool = false
	fmt.Println("userQ is ", userQ)
	fmt.Printf("Type of userQ is %T\n", userQ)

	// Numeric types
	/*
		uint8, uint16, uint32, uint64,
		int8, int16, int32, int64,
		float32, float64,
		complex64, complex128,
		byte --- alias for uint8
		rune --- alias for int32
	*/
	var pixelValue uint8 = 128
	fmt.Println("pixelValue is", pixelValue)
	fmt.Printf("Type of pixelValue is %T\n", pixelValue)

	var soundIntensity int32 = -30
	fmt.Println("soundIntensity is", soundIntensity, "dB")
	fmt.Printf("Type of soundIntensity is %T\n", soundIntensity)

	var temperature float32 = 98.6
	fmt.Println("temperature is", temperature, "degrees F")
	fmt.Printf("Type of temperature is %T\n", temperature)

	// String types
	var name string = "s4m13337"
	fmt.Println("The name is", name)
	fmt.Printf("Type of name is %T\n", name)
}
