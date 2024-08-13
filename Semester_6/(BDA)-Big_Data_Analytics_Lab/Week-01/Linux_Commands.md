# Linux File Operations

## 1. Create a File

```bash
touch filename.txt
```

## 2. Create a Directory

```bash
mkdir dirname
```

## 3. Copy a File

```bash
cp sourcefile.txt destination/
```

## 4. Copy a Directory and its Contents

```bash
cp -r sourcedir/ destination/
```

## 5. Move/Rename a File

```bash
mv oldfilename.txt newfilename.txt
```

## 6. Move/Rename a Directory

```bash
mv olddir/ newdir/
```

## 7. Remove/Delete a File

```bash
rm filename.txt
```

## 8. Remove/Delete a Directory and its Contents

```bash
rm -r dirname/
```

## 9. View Contents of a File

```bash
cat filename.txt
```

## 10. View Contents of a File with Pagination

```bash
less filename.txt
```

## 11. Edit a File

```bash
nano filename.txt
```

## 12. View File and Directory Information

```bash
ls -l
```

## 13. Change Directory

```bash
cd dirname/
```

## 14. Display Current Directory

```bash
pwd
```

## 15. Create Symbolic Link

```bash
ln -s targetfile symlink
```

## 16. Change File Permissions

```bash
chmod permissions filename.txt
```

## 17. Change Ownership of a File

```bash
chown newowner:newgroup filename.txt
```

## 18. Compress a File

```bash
gzip filename.txt
```

## 19. Extract a Compressed File

```bash
gunzip filename.txt.gz
```

## 20. Search for a File

```bash
find /path/to/search -name filename.txt
```
```
Note: Make sure to replace placeholders like `filename.txt`, `dirname`, `sourcedir/`, `destination/`, `oldfilename.txt`, `newfilename.txt`, `olddir/`, `newdir/`, `/path/to/search`, etc., with your actual file and directory names or paths.
