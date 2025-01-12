getTokenInfo argc: 2 [1:-th] 
getTokenInfo -th 
#### Usage

`Usage:`    getTokenInfo [-b|-n|-v|-h] &lt;address&gt; &lt;address&gt; [address...] [block...]  
`Purpose:`  Retrieve the token balance(s) for one or more addresses at the given (or latest) block(s).
             
`Where:`  

| Short Cut | Option | Description |
| -------: | :------- | :------- |
|  | address_list | two or more addresses (0x...), the first is an ERC20 token, balances for the rest are reported |
|  | block_list | an optional list of one or more blocks at which to report balances, defaults to 'latest' |
| -b | --byAcct | consider each address an ERC20 token except the last, whose balance is reported for each token |
| -n | --nozero | suppress the display of zero balance accounts |

#### Hidden options (shown during testing only)
| -i | --info val | retreive information [name&#124;decimals&#124;totalSupply&#124;version&#124;symbol&#124;all] about the token |
#### Hidden options (shown during testing only)

| -v | --verbose | set verbose level. Either -v, --verbose or -v:n where 'n' is level |
| -h | --help | display this help screen |

`Notes:`

- `addresses` must start with '0x' and be forty two characters long.
- `block_list` may be a space-separated list of values, a start-end range, a `special`, or any combination.
- This tool retrieves information from the local node or rpcProvider if configured (see documentation).
- If the token contract(s) from which you request balances are not ERC20 compliant, the results are undefined.
- If the queried node does not store historical state, the results are undefined.
- `special` blocks are detailed under `whenBlock --list`.

