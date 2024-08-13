from pyspark import SparkContext
from pyspark.sql import SparkSession

# Create a SparkContext
sc = SparkContext(appName="RDDExample")

# or 

# spark = SparkSession.builder \
#     .appName("EmpRecordss") \
#     .getOrCreate()

# Create an RDD from a list of numbers
rdd = sc.parallelize([1, 2, 3, 4, 5, 6, 7, 8, 9, 10])

# 1. map(func)
mapped_rdd = rdd.map(lambda x: x * 2)
print("map(func):", mapped_rdd.collect())

# 2. filter(func)
filtered_rdd = rdd.filter(lambda x: x % 2 == 0)
print("filter(func):", filtered_rdd.collect())

# 3. flatMap(func)
flat_mapped_rdd = rdd.flatMap(lambda x: (x, x * 2))
print("flatMap(func):", flat_mapped_rdd.collect())

# 4. reduce(func)
sum_of_elements = rdd.reduce(lambda x, y: x + y)
print("reduce(func):", sum_of_elements)

# 5. aggregate(zeroValue, seqOp, combOp)
aggregate_result = rdd.aggregate((0, 0),
                                 (lambda acc, value: (acc[0] + value, acc[1] + 1)),
                                 (lambda acc1, acc2: (acc1[0] + acc2[0], acc1[1] + acc2[1])))
print("aggregate(zeroValue, seqOp, combOp):", aggregate_result)

# 6. sortByKey(ascending=True)
sorted_rdd = rdd.map(lambda x: (x, x * 2)).sortByKey()
print("sortByKey(ascending=True):", sorted_rdd.collect())

# 7. groupByKey()
grouped_rdd = rdd.map(lambda x: (x % 2, x)).groupByKey().mapValues(list)
print("groupByKey():", grouped_rdd.collect())

# 8. reduceByKey(func)
reduced_by_key_rdd = rdd.map(lambda x: (x % 2, x)).reduceByKey(lambda x, y: x + y)
print("reduceByKey(func):", reduced_by_key_rdd.collect())

# 9. mapValues(func)
mapped_values_rdd = rdd.map(lambda x: (x % 2, x)).mapValues(lambda x: x * 2)
print("mapValues(func):", mapped_values_rdd.collect())

# 10. flatMapValues(func)
flat_mapped_values_rdd = rdd.map(lambda x: (x % 2, x)).flatMapValues(lambda x: (x, x * 2))
print("flatMapValues(func):", flat_mapped_values_rdd.collect())

# 11. join(otherRDD)
other_rdd = sc.parallelize([(1, 'a'), (2, 'b'), (3, 'c')])
joined_rdd = rdd.map(lambda x: (x % 3, x)).join(other_rdd)
print("join(otherRDD):", joined_rdd.collect())

# 12. leftOuterJoin(otherRDD), rightOuterJoin(otherRDD)
left_outer_joined_rdd = rdd.map(lambda x: (x % 3, x)).leftOuterJoin(other_rdd)
print("leftOuterJoin(otherRDD):", left_outer_joined_rdd.collect())
right_outer_joined_rdd = rdd.map(lambda x: (x % 3, x)).rightOuterJoin(other_rdd)
print("rightOuterJoin(otherRDD):", right_outer_joined_rdd.collect())

# 13. union(otherRDD)
union_rdd = rdd.union(other_rdd)
print("union(otherRDD):", union_rdd.collect())

# 14. intersection(otherRDD)
intersection_rdd = rdd.intersection(other_rdd)
print("intersection(otherRDD):", intersection_rdd.collect())

# 15. distinct()
distinct_rdd = rdd.flatMap(lambda x: (x, x * 2)).distinct()
print("distinct():", distinct_rdd.collect())

# 16. sample(withReplacement, fraction, seed)
sampled_rdd = rdd.sample(False, 0.5)
print("sample(withReplacement, fraction, seed):", sampled_rdd.collect())

# 17. take(n)
first_elements = rdd.take(3)
print("take(n):", first_elements)

# 18. collect()
all_elements = rdd.collect()
print("collect():", all_elements)

# 19. foreach(func)
rdd.foreach(lambda x: print(x))

# 20. persist(storageLevel)
rdd.persist()

# Stop the SparkContext
sc.stop()
spark.stop()
