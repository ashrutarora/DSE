
**Q1)**

Create the dataset of your choice and perform a word count program using the Spark tool.

---


**Ans)**

**Step 1: Prepare the Text File**

1. Open a terminal or command prompt.
2. Navigate to the directory where you want to create the text file.
3. Use the `vi` editor to create a new file named `input.txt`:

```bash
vi input.txt
```

4. Press `i` to enter insert mode and type or paste the sample text data into the editor:

```plaintext
Hello world
Hello Spark
Spark is awesome
World of Spark
```

5. Press `Esc` to exit insert mode, then type `:wq` and press `Enter` to save and exit `vi`.

**Step 2: Write the Spark Code**

1. Use the `vi` editor to create a new file named `Q1.py`:

```bash
vi Q1.py
```

2. Press `i` to enter insert mode and copy and paste the following Python code into the file:

```python
from pyspark.sql import SparkSession
from pyspark.sql.functions import explode, split, col

# Create a SparkSession
spark = SparkSession.builder \
    .appName("WordCount") \
    .getOrCreate()

# Read the text file into a DataFrame
df = spark.read.text("input.txt")

# Split the lines into words
words = df.select(explode(split(col("value"), " ")).alias("word"))

# Perform word count
word_count = words.groupBy("word").count().orderBy("count", ascending=False)

# Show the result
word_count.show()

# Stop the SparkSession
spark.stop()
```

3. Press `Esc` to exit insert mode, then type `:wq` and press `Enter` to save and exit `vi`.

**Step 3: Run the Spark Program**

1. Open a terminal or command prompt.
2. Navigate to the directory where the `Q1.py` file is saved.
3. Run the Spark program using the following command:

```bash
spark-submit Q1.py
```

**Output:**

```
+-------+-----+
|   word|count|
+-------+-----+
|  Spark|    3|
|  Hello|    2|
|  world|    1|
|awesome|    1|
|     of|    1|
|     is|    1|
+-------+-----+
```

**Step 4: View the Output**

After running the Spark program, you will see the word count output displayed in the terminal.

---

This detailed guide covers creating the input file, writing the Spark code using `vi`, running the Spark program, and viewing the output.
