# Not Redis

Again, is not a Redis, it's just me trying to make a [redis-cli](https://redis.io/docs/getting-started/)

## List of Commands

`db [command] [params]`

### get

Return a key-value pair if the key is exists on the database. If not exists, return an error.

**Example:**

```bash
$ make db get name

> name ["Ahmad"]
```

### set

_ToDo_

### keys

Return key-value pair(s) based on the pattern options given. If no pattern given, return an error.

#### Options

**all**
Get all data in the database

```bash
$ make db keys all
```

### help

Show the help.

## Run

```bash
$ make db [command] [params]
```

**Example:**

```bash
$ make db get name
```

```bash
$ make db set age 23
```
