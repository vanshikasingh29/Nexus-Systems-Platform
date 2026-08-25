# Engineering Design

## Design Goals

Nexus prioritises:

1. clear subsystem boundaries
2. explicit resource ownership
3. deterministic behaviour
4. testability
5. low-level transparency

## Why C?

C provides direct exposure to:

- memory,
- pointers,
- data representation,
- compilation,
- system interfaces.

This makes it appropriate for exploring operating-system concepts.

## Error Handling

Subsystem APIs return explicit status values where operations can fail.

Examples:

```text
0  -> failure
1  -> success
-1 -> invalid resource / creation failure