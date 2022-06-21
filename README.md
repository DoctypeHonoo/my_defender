<p align="center">
  <img src="https://user-images.githubusercontent.com/91092610/174764436-ad5db2d9-8418-4293-8646-82d410d70bc0.png" />
</p>
<h1 align="center">
   My_Defender
</h1>

---

## Motivation : 

Le **My_Defender** est un des 4 projets graphique de l'année, avec le My_Hunter/My_Screensaver, le My_Runner/My_Radar, et enfin le My_RPG. Il consiste à créer un jeu de type Tower Defense où l’objectif est de défendre une zone contre des vagues successives d’ennemis se déplaçant suivant un itinéraire en construisant et en améliorant progressivement des tours défensives.
<p align="center">
  <img src="https://user-images.githubusercontent.com/91092610/174764327-294dec7e-b8ec-4f8a-adb2-a4bc104b80ea.png"/>
</p>

---

## Description :

Lors de la réalisation du **My_Defender**, il est demandé d'avoir certaine caractéristiques sur le jeu : 
- Le joueur doit pouvoir construire des tours pour défendre son château
- Des vagues d'ennemis doivent apparaître régulièrement d'un côté de l'écran
- Le joueur doit pouvoir acheter des tours et les placer à des endroits prédéfinis sur la map
- Les tours peuvent être défensive ou attaquante
- Si un ennemie atteint le château, celui-ci doit subir des dégats
- Si le château n'a plus de vie, le joueur perd

---

## Fonctions Autorisées : 

- Toutes les fonctions de la CSFML
- Toutes les fonctions de la librairie Math
- malloc, free, memset, (s)rand, getline, (f)open, (f)read, (f)close, (f)write, opendir, readdir, closedir

---

## Installer & Lancer le Projet :

Ouvrez un terminal et dirigez vous ou vous souhaitez que le projet soit installé, puis exécutez les commandes suivantes : 
```bash
$ git clone git@github.com:DoctypeHonoo/my_rpg.git
$ cd my_rpg
$ make
```
Le binaire se trouvera alors à la racine du projet, et il vous suffira de le lancer comme ceci : 
```bash
$ ./my_rpg
```
<p align="center">
  <img src="https://user-images.githubusercontent.com/91092610/174756029-b3c80e79-a26a-419f-ad66-f43cd7f27ba9.png">
</p>

---

## Le Jeu : 

Le jeu que nous avons réalisé est un Pokemon like. Lors du lancement du binaire vous disposez d'un menu et il vous suffit de cliquer sur le bouton *Play* pour lancer, ou *Quit* pour quitter.
<p align="center">
  <img src="https://user-images.githubusercontent.com/91092610/174756708-5995d786-2970-47d9-8b4a-56cc003b2040.png">
</p>
Une fois le jeu lancé, le rendu graphique donne ceci : 
<p align="center">
  <img src="https://user-images.githubusercontent.com/91092610/174758130-cac31698-199f-4cc1-b1c7-94c66773131e.png">
</p>
Le jeu possède un système de collision totalement fonctionnel avec le décor et possède aussi un système de combat. Le premier se déroule dans la maison et haut à gauche de l'écran, quand au deuxième, le combat du boss, se déroule dans la grotte au milieu à droite.
<p align="center">
  <img src="https://user-images.githubusercontent.com/91092610/174759264-2d0758bb-c3dd-4a6e-a08e-9900e104f382.png">
</p>
<p align="center">
  <img src="https://user-images.githubusercontent.com/91092610/174759971-90c6c6dc-6231-4663-8927-0df57ebc7ca0.png">
</p>
