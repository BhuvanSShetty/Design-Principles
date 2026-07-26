# Interface and Abstract Class

This example shows two related ideas in C++:

- An **interface** defines what operations must exist.
- An **abstract class** can provide shared behavior and still leave some methods unfinished.

## In this example

- `IEngine` is the interface.
- It declares `start()` and `stop()` as pure virtual methods.
- `Car` is an abstract class.
- `Car` inherits from `IEngine` and implements `start()` once for all cars.
- `Car` still leaves `stop()` abstract, so it cannot be created directly.
- `HandBrakeCar` and `BrakeCar` are concrete classes.
- They complete the `stop()` behavior in different ways.

## What each concept means

### Interface

An interface is a contract.

It tells you what a class must do, but not how it must do it.

In this code, any engine-like object must support:

- `start()`
- `stop()`

### Abstract class

An abstract class is a base class that cannot be instantiated.

It is useful when you want:

- shared code
- shared data
- common behavior
- but still want derived classes to finish the missing parts

Here, `Car` gives all cars the same `start()` behavior, but lets each car decide how it stops.

### Polymorphism

Different car types can be treated through the same base type.

That is why `HandBrakeCar` and `BrakeCar` both behave like `Car`, and both also satisfy `IEngine`.

### Encapsulation

The `model` field is `protected`, so derived classes can use it, but outside code cannot change it directly.

### Inheritance

`Car` inherits from `IEngine`, and the concrete cars inherit from `Car`.

### Abstraction

The caller works with the idea of a car starting and stopping, without needing to know the exact stop mechanism.

## Main idea

Use an interface when you want a strict contract.

Use an abstract class when you want that contract plus shared implementation.

This example combines both so the design is easy to extend.