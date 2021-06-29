# Terminal-Based-Reminder
A terminal based reminder.

## Installation

Download the package as a .zip and extract. Change the marked lines in the files and then set the current working directory as the extracted directory and simply run this:

```bash
make
```

Then, add this line to the end of your .bash_aliases file in your home directory (create the file if it doesn't exist):


```bash
alias task='"{path to the directory}/addtask"'
```

## Usage

There are 7 modes to add a task. These are as following:

#### Hourly Tasks
```bash
task -h task_name
```

#### Daily Tasks
```bash
task -d task_name
```

#### Weekly Tasks
```bash
task -w task_name
```

#### Monthly Tasks
```bash
task -m task_name
```

#### Annual Tasks
```bash
task -y task_name
```

#### Same Day Tasks
```bash
task -t task_name HH MM
```

#### Non-repetitive Tasks
```bash
task task_name DD MM (or M) YYYY HH MM SS
```





