# Beágyazott és ambiens rendszerek (VIMIAC06) házi feladat
## Banánfa (nyomógomb)
Írjátok meg az alábbi játékot az STK3700-as kártyára!

### A játék célja

A feladat minél több lehulló gyümölcs begyűjtése négy banánfáról. A banánfákat elhagyó gyümölcsök az alsó (alfanumerikus) kijelző négy mezeje valamelyikén eshetnek le. Ezeket alul egy kosár segítségével kell elkapni.

### A játék indítása

A játék elején lehessen állítani a potyogás sebességét (pl. a PB0 gombbal pörgessetek egy nehézségi szint számlálót, amit a program megjelenít a kijelzőn, majd PB1-re indul a játék).

### A játék menete

Ha az egyik banánfán egy gyümölcs már nagyon érett, akkor ezt a hozzá tartozó mező legfelső vízszintes szegmensének kigyújtásával jelezzétek. Ezek után a banán egy meghatározott sebességgel elkezd lefele esni az adott mező középső függőleges szegmensein (értelem szerűen először a felső szegmenset éri el, majd az alsót). Ha a banán földet érésekor alatta volt a kosár, akkor sikerült elkapni. A kosarat a pozíciójának megfelelő mező alsó vízszintes szegmense jelképezi. Mozgatni pedig a PB0 ill. PB1 nyomógombokkal lehet balra ill. jobbra. Összesen 25 banán elkapására van lehetőség, utána vége van a játéknak. Az eddig lehullt illetve az elkapott banánok számát a felső (numerikus) kijelző egyik illetve másik oldali két-két digitjén jelezzétek (középen a kettősponttal elválasztva).


![image](https://github.com/serbanandi/bambi-hf/blob/7637c89ccdda8b4027ead1a4ff82fa68085d2d30/spec-img.png)
