
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
| `clear`       | `void`          | `void`     | Remove all items |
| `size`        | `void `         | `int`      | Get size of the list |
| `isEmpty`     | `void`          | `bool`     | If list is empty returns *true* |
| `addFirst`    | `object`        | `void`     | Add an item to the beginning |
| `addLast`     | `object`        | `void`     | Add an item to the end |
| `addTo`       | `int`, `object` | `void`     | Add an item to the *i*-th position |
| `get`         | `int`           | `object`   | Get *i*-th item |
| `getFirst`    | `void`          | `object`   | Get first item |
| `getLast`     | `void`          | `object`   | Get last item |
| `remove`      | `object`        | `bool`     | Remove specified item (returns *true* if removed) |
| `removeAt`    | `int`           | `object`   | Remove *i*-th item |
| `removeFirst` | `void`          | `object`   | Remove first item |
| `removeLast`  | `void`          | `object`   | Remove last item |
| `invert`      | `void`          | `void`     | Invert list |
| `find`        | `object`        | `int`      | Get index of the specified item |
| `contains`    | `object`        | `bool`     | If list contains specified item returns *true* |

### Dynamic array

```cpp
  DynamicArray<int> firstArray(12);
  DynamicArray<float> secondArray(arr, 15);
  DynamicArray<DynamicArray<double>> thirdArray;
```

**Template:** true

| Method         | Takes           | Returns    | Description |
| :------------  | :-------------- | :--------- | :---------- |
| `DynamicArray` | `void`          | `instance` | Default constructor |
| `DynamicArray` | `int`           | `instance` | Constructor with specified initial capacity |
| `DynamicArray` | `array`, `int`  | `instance` | Constructor from specified array |
| `clear`        | `void`          | `void`     | Remove all items |
| `size`         | `void `         | `int`      | Get size of the array |
| `isEmpty`      | `void`          | `bool`     | If array is empty returns *true* |
| `get`          | `int`           | `object`   | Get *i*-th item |
| `set`          | `int`, `object` | `void`     | Change *i*-th item |
| `sort`         | `bool`          | `void`     | Sort the array (optional: reversed sort) |
| `sortRange`    | `int`, `int`, `bool` | `void`| Sort specified range of the array |
| `append`       | `object`        | `void`     | Add new item to the end |
| `pop`          | `void`          | `object`   | Remove last item |
| `remove`       | `object`        | `bool`     | Remove specified item (returns *true* if removed) |
| `removeAt`     | `int`           | `object`   | Remove *i*-th item |
| `find`         | `object`        | `int`      | Get index of the specified item |
| `contains`     | `object`        | `bool`     | If list contains specified item returns *true* |

### Queue

```cpp
  Queue<int> firstQueue;
  Queue<float> secondQueue(6.9);
  Queue<Queue<double>> thirdQueue;
```

**Template:** true

| Method         | Takes           | Returns    | Description |
| :------------  | :-------------- | :--------- | :---------- |
| `Queue`        | `void`          | `instance` | Default constructor |
| `Queue`        | `object`        | `instance` | Constructor with initial value |
| `size`         | `void `         | `int`      | Get size of the queue |
| `isEmpty`      | `void`          | `bool`     | If array is empty returns *true* |
| `peek`         | `void`          | `object`   | Get first item |
| `pop`          | `void`          | `object`   | Remove first item |
| `push`         | `object`        | `void`     | Add new item to the end |