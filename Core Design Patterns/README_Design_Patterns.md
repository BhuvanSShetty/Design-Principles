# Design Patterns Handbook

A practical guide to the most common backend design patterns.

## Why Design Patterns?

Design patterns are proven, reusable solutions to common software design
problems. They help make software easier to extend, maintain and
understand. A pattern is not code that you copy---it is an idea that you
adapt to your problem.

------------------------------------------------------------------------

# 1. Factory Pattern

## Definition

A creational pattern that centralises object creation. The client
requests an object instead of creating it directly.

## When to use

-   Multiple implementations
-   Payment gateways
-   Database drivers
-   Notification providers

## Advantages

-   Loose coupling
-   Centralised creation
-   Easy to extend
-   Supports Open/Closed Principle

## Disadvantages

-   Extra abstraction
-   Unnecessary for very simple cases

------------------------------------------------------------------------

# 2. Singleton Pattern

## Definition

Ensures only one instance of a class exists and provides a global access
point.

## When to use

-   Logger
-   Configuration
-   Cache manager
-   Redis client

## Advantages

-   Single shared resource
-   Consistent state
-   Resource efficient

## Disadvantages

-   Harder to test
-   Global state
-   Easy to misuse

------------------------------------------------------------------------

# 3. Builder Pattern

## Definition

Builds complex objects step by step instead of using large constructors.

## When to use

-   Request objects
-   Configurations
-   SQL query builders

## Advantages

-   Readable
-   Supports optional fields
-   Method chaining

## Disadvantages

-   More classes
-   More boilerplate

------------------------------------------------------------------------

# 4. Adapter Pattern

## Definition

Allows incompatible interfaces to work together.

## When to use

-   Third-party SDKs
-   Legacy systems
-   External APIs

## Advantages

-   Decouples code
-   Easy provider replacement

## Disadvantages

-   Extra wrapper class

------------------------------------------------------------------------

# 5. Strategy Pattern

## Definition

Encapsulates multiple algorithms behind one interface and chooses one at
runtime.

## When to use

-   Payment methods
-   Authentication
-   Compression
-   Routing

## Advantages

-   Runtime flexibility
-   Removes if-else chains

## Disadvantages

-   More classes
-   Client selects strategy

------------------------------------------------------------------------

# 6. Observer Pattern

## Definition

One object notifies many dependent objects when its state changes.

## When to use

-   Events
-   Kafka
-   RabbitMQ
-   Notifications
-   WebSockets

## Advantages

-   Loose coupling
-   Event driven

## Disadvantages

-   Harder debugging
-   Performance with many observers

------------------------------------------------------------------------

# 7. Decorator Pattern

## Definition

Adds behaviour to an object dynamically without changing its original
class.

## When to use

-   Middleware
-   Logging
-   Authentication
-   Caching

## Advantages

-   Runtime extensibility
-   Composition over inheritance

## Disadvantages

-   Nested wrappers
-   More classes

------------------------------------------------------------------------

# 8. Facade Pattern

## Definition

Provides one simple interface to a complex subsystem.

## When to use

-   Checkout
-   User service
-   SDK wrappers

## Advantages

-   Hides complexity
-   Reduces coupling

## Disadvantages

-   Can become too large

------------------------------------------------------------------------

## Quick Comparison

  Pattern     Purpose
  ----------- --------------------------------
  Factory     Create objects
  Singleton   One shared instance
  Builder     Build complex objects
  Adapter     Bridge incompatible interfaces
  Strategy    Select algorithms
  Observer    Notify listeners
  Decorator   Add behaviour
  Facade      Simplify complex systems
