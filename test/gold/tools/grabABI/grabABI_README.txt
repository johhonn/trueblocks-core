grabABI argc: 2 [1:-th] 
grabABI -th 
#### Usage

`Usage:`    grabABI [-c|-g|-d|-e|-j|-n|-o|-l|-v|-h] addr  
`Purpose:`  Fetches the ABI for a smart contract. Optionally generates C++ source code representing that ABI.
             
`Where:`  

| Short Cut | Option | Description |
| -------: | :------- | :------- |
|  | addr | the address(es) of the smart contract(s) to grab |
| -c | --canonical | convert all types to their canonical represenation and remove all spaces from display |
| -g | --generate | generate C++ code into the current folder for all functions and events found in the ABI |
| -d | --data | export the display as data |
| -e | --encode | generate the encodings for the functions / events in the ABI |
| -j | --json | print the ABI to the screen as json |
| -n | --noconst | generate encodings for non-constant functions and events only (always true when generating) |
| -o | --open | open the ABI file for editing, download if not already present |
| -l | --sol fn | create the ABI file from a .sol file in the local directory |

#### Hidden options (shown during testing only)
| -s | --silent | if ABI cannot be acquired, fail silently (useful for scripting) |
| -n | --nodec | do not decorate duplicate names |
| -k | --known | load common 'known' ABIs from cache |
#### Hidden options (shown during testing only)

| -v | --verbose | set verbose level. Either -v, --verbose or -v:n where 'n' is level |
| -h | --help | display this help screen |

`Notes:`

- Use the `--silent` option, which displays fewer messages, for scripting.

