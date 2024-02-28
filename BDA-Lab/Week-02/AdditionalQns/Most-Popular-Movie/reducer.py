current_rating = None
current_count = 0

for line in sys.stdin:
    rating, count = line.strip().split('\t')
    count = int(count)

    if current_rating == rating:
        current_count += count
    else:
        if current_rating:
            print(f"Rating {current_rating}: {current_count} movies")
        current_rating = rating
        current_count = count

if current_rating:
    print(f"Rating {current_rating}: {current_count} movies")
