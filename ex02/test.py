import os
import random

def generate_random_numbers(num_tests, num_numbers):
    test_cases = []
    for _ in range(num_tests):
        test_case = [random.randint(1, 100) for _ in range(num_numbers)]
        test_cases.append(test_case)
    return test_cases

def execute_c_program(input_numbers):
    input_str = ' '.join(map(str, input_numbers))
    command = f'./PmergeMe {input_str}'
    # print(f"Executing command: {command}")
    output = os.popen(command).read()
    return output

def is_sorted(numbers):
    return all(numbers[i] <= numbers[i+1] for i in range(len(numbers)-1))

def main():
    num_tests = int(input("Enter the number of tests: "))
    num_numbers = int(input("Enter the number of numbers in each test: "))
    test_cases = generate_random_numbers(num_tests, num_numbers)

    for idx, test_case in enumerate(test_cases):
        output = execute_c_program(test_case)
        if "bad input" in output:
            print(f"Test case {idx + 1} produced bad input: {test_case}")
            continue
        if not output:
            print(f"Failed to execute test case {idx + 1}: {test_case}")
            continue
        try:
            output_lines = output.splitlines()
            if not output_lines:
                print(f"Empty output for test case {idx + 1}: {test_case}")
                continue
            sorted_numbers_str = output_lines[0][6:]
            sorted_numbers = list(map(int, sorted_numbers_str.split()))
            if len(sorted_numbers) != len(test_case):
                print(f"Test case {idx + 1} failed: number count mismatch. Input: {test_case}, Output: {sorted_numbers}")
                break
            if not is_sorted(sorted_numbers):
                print(f"Test case {idx + 1} failed: {test_case}")
                break
        
        except (IndexError, ValueError) as e:
            print(f"Error processing output for test case {idx + 1}: {test_case}")
            print(f"Output: {output}")
            break
    else:
        print("All test cases passed successfully.")

if __name__ == "__main__":
    main()
