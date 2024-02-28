

current_month = None
total_temperature = 0
count = 0

for line in sys.stdin:
    month, temperature = line.strip().split('\t')
    temperature = float(temperature)

    if current_month == month:
        total_temperature += temperature
        count += 1
    else:
        if current_month:
            average_temperature = total_temperature / count
            print(f"{current_month}\t{average_temperature:.2f}")
        current_month = month
        total_temperature = temperature
        count = 1

if current_month:
    average_temperature = total_temperature / count
    print(f"{current_month}\t{average_temperature:.2f}")
