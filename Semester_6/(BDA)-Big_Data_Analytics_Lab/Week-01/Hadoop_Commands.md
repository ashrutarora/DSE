# Interacting with HDFS using Command Line Interface

### Note - You can replace ```hadoop fs``` with ```hdfs dfs```

## Create a directory in HDFS
```bash
hadoop fs -mkdir /path/to/directory
```

## Create an empty file
```bash
hadoop fs -touchz /path/to/empty_file
```

## Copy files/folders from local file system to HDFS store
```bash
hadoop fs -copyFromLocal /local/path/file_or_folder /hdfs/path/
```

## Print file contents
```bash
hadoop fs -cat /path/to/file
```

## Copy files/folders from HDFS store to local file system
```bash
hadoop fs -copyToLocal /hdfs/path/file_or_folder /local/path/
```

## Move file from local to HDFS
```bash
hadoop fs -moveFromLocal /local/path/file /hdfs/path/
```

## Copy files within HDFS
```bash
hadoop fs -cp /source/hdfs/path/file_or_folder /destination/hdfs/path/
```

## Move files within HDFS
```bash
hadoop fs -mv /source/hdfs/path/file_or_folder /destination/hdfs/path/
```

## Size of each file in directory
```bash
hadoop fs -du /path/to/directory
```

## Total size of directory/file
```bash
hadoop fs -du -s /path/to/directory_or_file
```

## Last modified time of directory or path
```bash
hadoop fs -stat /path/to/directory_or_file
```

## Change the replication factor of a file/directory in HDFS
```bash
hadoop fs -setrep -R <replication_factor> /path/to/directory_or_file
```

## List the contents of a directory in HDFS
```bash
hadoop fs -ls /path/to/directory
```

## Remove a file from HDFS
```bash
hadoop fs -rm /path/to/file
```

## Change File Permissions
```bash
hadoop fs -chmod <permissions> /path/to/file_or_directory
```

## Changing File Ownership
```bash
hadoop fs -chown <user:group> /path/to/file_or_directory
```

## Checksum Calculation
```bash
hadoop fs -checksum /path/to/file
```

## File Concatenation
```bash
hadoop fs -getmerge /source/hdfs/path/ /local/path/destination_file
```

## File Compression/Decompression
```bash
# Compress
hadoop fs -Dmapreduce.job.compress=true -Dmapreduce.map.output.compress=true -Dmapreduce.output.fileoutputformat.compress=true -Dmapreduce.output.fileoutputformat.compress.codec=org.apache.hadoop.io.compress.GzipCodec -put /local/path/file /hdfs/path/compressed_file

# Decompress
hadoop fs -text /hdfs/path/compressed_file | gunzip > /local/path/decompressed_file
```

## lsFile Block Location Information
```bash
hdfs fsck /path/to/file -files -blocks -locations
```

## File Encryption/Decryption
Encryption and decryption are not straightforward with Hadoop CLI. These operations are typically handled at a higher level using tools like Hadoop Key Management Server (KMS) or Transparent Data Encryption (TDE).


Please note that some of these commands may require additional configuration based on your Hadoop setup, and the examples provided assume a basic Hadoop environment. Adjust the paths, file names, and options according to your specific use case and Hadoop cluster configuration.
