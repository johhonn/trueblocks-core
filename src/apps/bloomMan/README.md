## bloomMan

***
**Note:** This tool is available through [our website](http://quickblocks.io). Contact us at [sales@greathill.com](mailto:sales@greathill.com) for more information.
***

#### Usage

`Usage:`    bloomMan [-s|-r|-c|-u|-b|-u|-v|-h] lists  
`Purpose:`  Work with EABs, raw blooms and/or present statistics.  
`Where:`  

| Short Cut | Option | Description |
| -------: | :------- | :------- |
|  | lists | list of block_nums or block_nums and addrs (if both, show hit stats for addrs) |
| -s | --stats | calculate statistics for blooms in the block range |
| -r | --rewrite | re-write the given bloom(s) -- works only with block numbers |
| -c | --check | check that a bloom contains all addresses in the given block(s) |
| -u | --upgrade | read, then write, all blooms (effectivly upgrading them) |
| -b | --bucket val | for --stats only, optional bucket size |
| -u | --cum | for --stats only, stats are cummulative (per bucket otherwise) |
| -v | --verbose | set verbose level. Either -v, --verbose or -v:n where 'n' is level |
| -h | --help | display this help screen |

#### Other Options

All **QBlocks** command-line tools support the following commands (although in some case, they have no meaning):

    Command     |     Description
    -----------------------------------------------------------------------------
    --version   |   display the current version of the tool
    --nocolor   |   turn off colored display
    --wei       |   specify value in wei (the default)
    --ether     |   specify value in ether
    --dollars   |   specify value in US dollars
    --raw       |   report JSON data from the node with minimal processing
    --veryRaw   |   report JSON data from node with zero processing
    --fmt       |   export format (where appropriate). One of [none|txt|csv|json|api]
    --api_mode  |   simulate api_mode for testing
    --file:fn   |   specify multiple sets of command line options in a file.

<small>*For the `--file:fn` option, place a series of valid command lines in a file and use the above options. In some cases, this option may significantly improve performance. A semi-colon at the start of a line makes that line a comment.*</small>

**Powered by Qblocks<sup>&trade;</sup>**


