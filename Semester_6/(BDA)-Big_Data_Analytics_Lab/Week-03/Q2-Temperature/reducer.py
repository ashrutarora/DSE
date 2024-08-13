#!/usr/bin/python3

current_year, temperatures = None, []

for line in sys.stdin:
    year, temperature = line.strip().split("\t")
    temperature = int(temperature)

    if current_year != year:
        if current_year is not None:
            avg_temp = sum(temperatures) / len(temperatures)
            min_temp, max_temp = min(temperatures), max(temperatures)
            print(f"{current_year}\tAverage Temperature: {avg_temp:.2f}\tMinimum Temperature: {min_temp}\tMaximum Temperature: {max_temp}")
        
        current_year, temperatures = year, [temperature]
    else:
        temperatures.append(temperature)

# Output for the last year
if current_year is not None:
    avg_temp = sum(temperatures) / len(temperatures)
    min_temp, max_temp = min(temperatures), max(temperatures)
    print(f"{current_year}\tAverage Temperature: {avg_temp:.2f}\tMinimum Temperature: {min_temp}\tMaximum Temperature: {max_temp}")