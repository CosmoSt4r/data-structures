
# Data structures implementation on C++

My implementation of most popular data structures on C++ language


## Implemented structures

### Data structures
- Doubly linked list
- Dynamic Array
- Queue
- Stack

### Math structures
- Complex number
- Fraction


## Documentation

### Doubly linked list

```cpp
  DLinkedList<int> firstList;
  DLinkedList<float> secondList;
  DLinkedList<DLinkedList<double>> thirdList;
```

**Template:** true

| Method        | Takes           | Returns    | Description |
| :------------ | :-------------- | :--------- | :---------- |
| `DLinkedList` | `void`          | `instance` | Default constructor |
| `clear`       | `void`          | `void`     | Remove all elements |
| `size`        | `void `         | `int`      | Get size of the list |
| `isEmpty`     | `void`          | `bool`     | If list is empty returns *true* |
| `addFirst`    | `object`        | `void`     | Add an item to the beginning |
| `addLast`     | `object`        | `void`     | Add an item to the end |
| `addTo`       | `int`, `object` | `void`     | Add an item to the *i*-th position |
| `get`         | `int`           | `object`   | Get *i*-th element |
| `getFirst`    | `void`          | `object`   | Get first element |
| `getLast`     | `void`          | `object`   | Get last element |
| `remove`      | `object`        | `bool`     | Remove specified item (returns *true* if removed) |
| `removeAt`    | `int`           | `object`   | Remove *i*-th element |
| `removeFirst` | `void`          | `object`   | Remove first element |
| `removeLast`  | `void`          | `object`   | Remove last element |
| `invert`      | `void`          | `void`     | Invert list |
| `find`        | `object`        | `int`      | Find specified item |
| `contains`    | `object`        | `bool`     | If list contains specified item returns *true* |

### Dynamic array

```cpp
  DynamicArray<int> firstArray;
  DynamicArray<float> secondArray;
  DynamicArray<DynamicArray<double>> thirdArray;
```

**Template:** true

| Method         | Takes           | Returns    | Description |
| :------------  | :-------------- | :--------- | :---------- |
| `DynamicArray` | `void`          | `instance` | Default constructor |
| `DynamicArray` | `int`           | `instance` | Constructor with specified initial capacity |
| `DynamicArray` | `array`, `int`  | `instance` | Constructor from specified array |
| `clear`        | `void`          | `void`     | Remove all elements |
| `size`         | `void `         | `int`      | Get size of the array |
| `isEmpty`      | `void`          | `bool`     | If array is empty returns *true* |
| `get`          | `int`           | `object`   | Get *i*-th element |
| `set`          | `int`, `object` | `void`     | Change *i*-th element |
| `sort`         | `bool`          | `void`     | Sort the array (optional: reversed sort) |
| `sortRange`    | `int`, `int`, `bool` | `void`| Sort specified range of the array |
| `append`       | `object`        | `void`     | Add new item to the end |
| `pop`          | `void`          | `object`   | Remove last item |
| `remove`       | `object`        | `bool`     | Remove specified item (returns *true* if removed) |
| `removeAt`     | `int`           | `object`   | Remove *i*-th element |
| `find`         | `object`        | `int`      | Find specified item |
| `contains`     | `object`        | `bool`     | If list contains specified item returns *true* |