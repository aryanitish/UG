Cover image(CI) : dollar.png
PCA of cover image : coverImgPca.csv
Message image(MI) : womanFace.png
PCA of message image : messageImgPca.csv

Steganographed PCA(i.e MI's pc's scaled and entailed to CI's pc's) : coverImgPcaSteg.csv
Steganographed image : cvrMsgReconst299n200.png

PCA of Steganographed image(cvrMsgReconst299n200.png) : reCoverPca.csv

Cover Image recovery from Steganographed image(cvrMsgReconst299n200.png) : StegRecCovImg.png

MI's PCA(eigen values) obatined from Steganographed image(cvrMsgReconst299n200.png) : StegObtndMsgPca.csv

Message Image recovery try from recovered MI's PCA(StegObtndMsgPca.csv), i.e FINAL MESSAGE IMAGE OBTAINED : StegRecMesgImg.png



PCA cutoff in cover image : ~60%, first 299 pc's of total 499 
	HIGHEST eigen value in cover : 367.8679 

PCA cutoff in message image : 499 - 299 = first 200 of total 511 pc's
	HIGHEST eigen value in message : 93.8058

After placing MI's 200 pc's after CI's 299 pc's and then reconstructing the cover image with message steganographed, no visible distortions were found.
However, after calculating PCA of the restored steganographed image and checking the 300th pc(as we fixed MI from here on in CI), discrepancies were noted. 
	PC300 in steg. cover img(Original scaled MI's highest pc) = 0.255 
	PC300 in recovered steg. img = 0.1418
Trying to reconstruct MI from recovered cover image(i.e taking last 200 pc's and using MI's scaling matrices) yielded nothing close to original MI.
