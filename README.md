# CMC Maker Cpp version

`Version 1.0.0`

Date: August 17th, 2021

Author: Yige Huang

## Usage

### Compile

> Modify `main.cxx` if you want to change the output.
>
> After that, run `make` or `make cmc`.
>
> You can compile `test.cxx` by running `make test`, and `bin/test` to do a simple check.
>
> `make help` for further help information.

### Run executabel cmc

> Run `bin/cmc` to generate root file (default name "CmcEvents.root).
>
> Run `bin/cmc PATH_TO_WANTED_FILE` to generate root file named as you want.

## Data structure of root file

> TTree: CMC
>
>> mul
>>
>> px
>>
>> py
>>
>> pxStep
>>
>> pyStep
>
> TH1D: hPx
>
> TH1D: hPy
>
> TH1D: hPxStep
>
> TH1D: hPyStep