# SOLID Principles

> "Good software is not software that works today. Good software is software that can still be changed tomorrow."

SOLID is a collection of **five object-oriented design principles** introduced by **Robert C. Martin (Uncle Bob)** to help developers write software that is easier to maintain, extend, test, and understand.

These principles are not programming language features or design patterns. They are **guidelines** for designing classes and relationships between classes.

---

# Why SOLID?

Imagine you build a project with 50 classes.

Everything works.

Six months later, your manager asks:

- Add a new payment method.
- Change the database.
- Replace the email provider.
- Support multiple cloud providers.

Without good design, a small change can force modifications across dozens of files, increasing the risk of introducing bugs.

SOLID helps us design software so that changes are **localized**, predictable, and easier to implement.

---

# The Five SOLID Principles

```
S - Single Responsibility Principle
O - Open/Closed Principle
L - Liskov Substitution Principle
I - Interface Segregation Principle
D - Dependency Inversion Principle
```

Each principle solves a different design problem.

---

# 1. Single Responsibility Principle (SRP)

## Definition

> A class should have only one reason to change.

In simpler words:

> A class should have one well-defined responsibility.

---

## Why was SRP introduced?

Many beginners create "God Classes" that perform multiple unrelated tasks.

For example, a single class might:

- Validate data
- Save data
- Send emails
- Generate reports
- Log activities

Whenever one of these behaviours changes, the entire class must be modified.

This makes maintenance difficult and increases the chance of bugs.

---

## Philosophy

Every class should focus on doing **one thing well**.

If a class has multiple unrelated responsibilities, split those responsibilities into separate classes.

---

## When to use

SRP should be applied almost everywhere.

Typical examples include:

- EmailService
- Logger
- UserRepository
- PaymentService
- AuthenticationService

Each class should perform one specific task.

---

## Advantages

- Easier to maintain
- Easier to understand
- Easier to test
- Better code reuse
- Lower coupling
- Higher cohesion

---

## Disadvantages

- Can increase the number of classes.
- Overusing SRP may create many tiny classes.

---

## Real-world analogy

Imagine a restaurant.

The chef cooks.

The waiter serves food.

The cashier collects payments.

If one person performs all three jobs, the restaurant becomes difficult to manage.

---

# 2. Open/Closed Principle (OCP)

## Definition

> Software entities should be open for extension but closed for modification.

In simpler words:

> You should be able to add new functionality without modifying existing code.

---

## Why was OCP introduced?

As software grows, new requirements constantly appear.

If adding one feature requires modifying existing classes, there is always a risk of breaking working code.

OCP encourages extending behaviour instead of changing existing implementations.

---

## Philosophy

Instead of editing existing classes, create new classes that extend existing behaviour.

Think of software as building blocks that can grow without changing their foundation.

---

## When to use

Whenever new behaviours are expected.

Examples:

- Payment methods
- Notification providers
- Database providers
- Authentication mechanisms
- File parsers

---

## Advantages

- Existing code remains stable.
- Easy to introduce new features.
- Lower risk of regression bugs.
- Encourages polymorphism.

---

## Disadvantages

- Requires abstractions.
- More classes and interfaces.
- Can become over-engineered for very small projects.

---

## Real-world analogy

A smartphone supports installing new apps.

The operating system itself doesn't need to be rewritten every time a new app is installed.

The phone is closed for modification but open for extension.

---

# 3. Liskov Substitution Principle (LSP)

## Definition

> Objects of a derived class should be replaceable with objects of the base class without changing the correctness of the program.

In simpler words:

> If B is a child of A, then B should behave like A.

---

## Why was LSP introduced?

Inheritance is often misused.

Developers sometimes inherit classes simply to reuse code, even when the child cannot properly behave like the parent.

This results in unexpected behaviour and runtime failures.

---

## Philosophy

Inheritance represents an **"is-a" relationship**.

If a child cannot honour the parent's behaviour, inheritance is probably the wrong choice.

---

## When to use

Whenever inheritance is involved.

Always ask:

> "Can my child safely replace its parent?"

If the answer is no, reconsider the design.

---

## Advantages

- Reliable inheritance hierarchies
- Better polymorphism
- Fewer runtime surprises
- Easier maintenance

---

## Disadvantages

- May require redesigning class hierarchies.
- Sometimes composition is a better alternative.

---

## Real-world analogy

A Sparrow is a Bird.

A Sparrow behaves like a Bird.

A Penguin is also a Bird.

But if your design assumes every Bird can fly, Penguins break that expectation.

The problem isn't the Penguin—it is the incorrect abstraction.

---

# 4. Interface Segregation Principle (ISP)

## Definition

> Clients should not be forced to depend on interfaces they do not use.

In simpler words:

> Don't force classes to implement methods they don't need.

---

## Why was ISP introduced?

Large interfaces often contain many unrelated methods.

Different implementations support different capabilities.

Forcing every implementation to implement every method leads to unnecessary code and exceptions.

---

## Philosophy

Instead of one large interface, create several small, focused interfaces.

Each class should implement only the behaviours it actually supports.

---

## When to use

Whenever interfaces begin growing too large.

Common examples include:

- Storage providers
- Payment gateways
- Notification systems
- Authentication services

---

## Advantages

- Smaller interfaces
- Better maintainability
- Easier testing
- Lower coupling
- Clearer responsibilities

---

## Disadvantages

- More interfaces
- Slightly more project structure

---

## Real-world analogy

A basic printer can print.

A multifunction printer can print, scan and fax.

It makes no sense to force every printer to support scanning and faxing.

---

# 5. Dependency Inversion Principle (DIP)

## Definition

> High-level modules should not depend on low-level modules. Both should depend on abstractions.

In simpler words:

> Depend on interfaces, not concrete implementations.

---

## Why was DIP introduced?

Business logic should not care about implementation details.

If your application directly depends on MySQL, changing to PostgreSQL becomes difficult.

Instead, depend on an abstraction representing a database.

The implementation can then be replaced without changing business logic.

---

## Philosophy

Business logic should remain stable while implementation details remain interchangeable.

Interfaces act as contracts between different parts of the system.

---

## When to use

Whenever one component depends on another.

Examples include:

- Database access
- Email providers
- Payment gateways
- Cloud storage
- Logging frameworks

---

## Advantages

- Loose coupling
- Easier testing
- Easier replacement of implementations
- Better maintainability
- Supports Dependency Injection

---

## Disadvantages

- More interfaces
- Slightly higher design complexity
- Unnecessary for very small applications

---

## Real-world analogy

A laptop depends on a USB-C port, not on a specific charger.

Whether you use an Apple charger, Dell charger or HP charger, the laptop works because it depends on the USB-C standard rather than one manufacturer's implementation.

---

# SOLID at a Glance

| Principle | Main Idea | Goal |
|------------|-----------|------|
| SRP | One responsibility | Easier maintenance |
| OCP | Extend without modifying | Safer feature additions |
| LSP | Child behaves like parent | Correct inheritance |
| ISP | Small focused interfaces | Avoid unnecessary methods |
| DIP | Depend on abstractions | Loose coupling |

---

# Relationship Between SOLID Principles

Although each principle solves a different problem, they often work together.

For example:

- OCP is usually achieved using abstractions.
- DIP introduces those abstractions.
- LSP ensures implementations correctly follow those abstractions.
- ISP keeps abstractions small and focused.
- SRP keeps every class focused on one responsibility.

Together, they produce software that is easier to understand, extend, and maintain.

---

# Final Thoughts

SOLID principles are not strict rules.

Sometimes breaking a principle results in simpler software.

The goal is not to apply SOLID everywhere, but to understand the trade-offs and apply the principles where they genuinely improve the design.

Experienced developers use SOLID as a guide rather than a checklist.