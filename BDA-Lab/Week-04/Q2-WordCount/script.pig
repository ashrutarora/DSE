-- Load data from a local text file
data = LOAD 'input_text.txt' AS (line:chararray);

-- Tokenize each line into words
words = FOREACH data GENERATE FLATTEN(TOKENIZE(line)) AS word;

-- Group by word and count occurrences
word_count = GROUP words BY word;
word_occurrences = FOREACH word_count GENERATE group AS word, COUNT(words) AS occurrences;

-- Store the result
STORE word_occurrences INTO 'output_word_count';
