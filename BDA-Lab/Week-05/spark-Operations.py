from pyspark.sql import SparkSession

# Create a SparkSession
spark = SparkSession.builder \
    .appName("SparkFunctionsExample") \
    .getOrCreate()

# Create a DataFrame from a list of tuples
data = [("John", 26, 30000),
        ("Jack", 40, 80000),
        ("Joshi", 25, 35000),
        ("Jash", 35, 75000),
        ("Yash", 40, 60000),
        ("Smith", 20, 24000),
        ("Lion", 42, 56000),
        ("kate", 50, 76000),
        ("cassy", 51, 40000),
        ("ronald", 57, 65000),
        ("John", 26, 30000),
        ("Smith", 20, 24000),
        ("Jash", 35, 75000),
        ("cassy", 51, 40000)]

columns = ["name", "age", "salary"]
df = spark.createDataFrame(data, columns)

# 1. select
selected_df = df.select("name", "salary")
selected_df.show()

# 2. filter
filtered_df = df.filter(df.age > 30)
filtered_df.show()

# 3. groupBy
grouped_df = df.groupBy("name").agg({"age": "avg", "salary": "sum"})
grouped_df.show()

# 4. orderBy
ordered_df = df.orderBy("age", ascending=False)
ordered_df.show()

# 5. withColumn
with_column_df = df.withColumn("age_plus_10", df.age + 10)
with_column_df.show()

# 6. drop
dropped_df = df.drop("age")
dropped_df.show()

# 7. join
other_data = [("John", "Manager"),
              ("Jack", "Director"),
              ("Joshi", "Engineer")]

other_columns = ["name", "designation"]
other_df = spark.createDataFrame(other_data, other_columns)

joined_df = df.join(other_df, "name", how="inner")
joined_df.show()

# 8. distinct
distinct_df = df.distinct()
distinct_df.show()

# 9. sample
sampled_df = df.sample(fraction=0.5, withReplacement=False, seed=42)
sampled_df.show()

# 10. union
union_df = df.union(other_df)
union_df.show()

# 11. intersect
intersect_df = df.intersect(other_df)
intersect_df.show()

# 12. subtract
subtract_df = df.subtract(other_df)
subtract_df.show()

# 13. dropDuplicates
drop_duplicates_df = df.dropDuplicates(["name", "age"])
drop_duplicates_df.show()

# Stop the SparkSession
spark.stop()
