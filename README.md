# Terminal-Based-Reminder
A terminal based reminder.

## Installation

Download the package as a .zip and extract. Change the marked lines in the files. Then, set the current working directory as the extracted directory and run these lines:

```bash
make
chmod +x reminder.sh
```


Then, add this line to the end of your .bash_aliases file in your home directory (create the file if it doesn't exist):


```bash
alias task='"{path to the directory}/addtask"'
```

Add reminder.sh to the Startup Applications to make the reminder run regularly.

## Usage

There are 6 modes to add a task. These are as following:

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

#### Non-repetitive Tasks
```bash
task task_name DD MM (or M) YYYY HH MM SS
```

If the task you're going to add is within the same day, you can simply run the line below as well:
```bash
task -t task_name HH MM
```




