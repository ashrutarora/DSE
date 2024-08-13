-- Load ratings data
ratings = LOAD 'ratings.data' AS (userID:int, movieID:int, rating:int, timestamp:long);

-- Group by movie ID and calculate average rating
average_ratings = FOREACH (GROUP ratings BY movieID) {
    avg_rating = AVG(ratings.rating);
    GENERATE group AS movieID, avg_rating;
}

-- Load movies data
movies = LOAD 'movies.item' USING PigStorage('|') AS (movieID:int, title:chararray, releaseDate:chararray, imdbLink:chararray);

-- Join ratings and movies data
joined_data = JOIN average_ratings BY movieID, movies BY movieID;

-- Order by average rating in descending order
sorted_data = ORDER joined_data BY avg_rating DESC;

-- Take the top record to get the most popular movie
most_popular_movie = LIMIT sorted_data 1;

-- Store the result
STORE most_popular_movie INTO 'output_most_popular_movie' USING PigStorage(',');
