package main

import (
	"bufio"
	"fmt"
	"os"
	"log"
	"strconv"
	"strings"
)

func main() {
	fmt.Print("Enter a grade: ")
	reader := bufio.NewReader(os.Stdin)
	input, err := reader.ReadString('\n')
	if err != nil {
		log.Fatal(err)
	}

	input = strings.TrimSpace(input)
	grade, err := strconv.ParseFloat(input,64)
	if err != nil {
		log.Fatal(err)
	}

	fmt.Println(grade)

	if grade >= 60 {
		fmt.Println("You pass!")
	} else if grade < 60 {
		fmt.Println("You fail!")
	}
}
