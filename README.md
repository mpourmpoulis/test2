![Image of Yaktocat](https://github.com/mpourmpoulis/test2/blob/master/test.png)
https://join.skype.com/invite/pD2XpiXJatDi
Period | Freq(Synth)
-------|-----------
7.574ns | 132.035MHz
7.618ns | 131.272MHz
6.240ns | 160.256MHz
6.284ns | 159.134MHz
5.879ns | 170.090MHz
6.027ns | 165.913MHz
3.921ns | 255.069MHz
3.921ns | 255.069MHz


Period | Freq(Synth) | 2 | 3 | 4 | 6 | R 
-------|-------------|---|---|---|---|---
7.574ns|132.035MHz|64|828|190|0|640
7.618ns|131.272MHz|64|828|190|0|640
6.240ns|160.256MHz|64|832|192|0|640
6.284ns|159.134MHz|64|832|192|0|640
5.879ns|170.090MHz|0|896|256|0|768
6.027ns|165.913MHz|0|768|256|0|640
3.921ns|255.069MHz|128|768|128|128|896
3.921ns|255.069MHz|128|544|128|128|672


![](https://github.com/mpourmpoulis/PythonVoiceCodingPlugin/blob/master/doc/gif/d2.gif)



gggg


[1] https://www.researchgate.net/publication/252066408_Finite-state_spell-checking_with_weighted_language_and_error_models


[2] http://www.openfst.org/twiki/bin/view/Forum/FstForum#Delayed%20composition%20via%20Python%20A

[3] https://www.aclweb.org/anthology/W16-2324/


This latency might be due concerns raised in [2] that is through the scripting api, compositiona are performed fully before taking shortest paths. In contrast, in [3] it appears to me that the composition is performed on a more "lazy" manner to get speed.
