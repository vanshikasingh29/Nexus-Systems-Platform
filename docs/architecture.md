# Nexus Architecture

Nexus is organised into independent systems subsystems.

```text
                    Nexus Runtime
                         |
        +----------------+----------------+
        |                |                |
     Processes        Memory         Concurrency
        |                |                |
        +----------------+----------------+
                         |
                     Scheduler
                         |
        +----------------+----------------+
        |                                 |
    Compiler                          Network
        |                                 |
        +----------------+----------------+
                         |
                   Virtualisation