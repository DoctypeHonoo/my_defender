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
$ git clone git@github.com:DoctypeHonoo/my_defender.git
$ cd my_defender
$ make
```
Le binaire se trouvera alors à la racine du projet, et il vous suffira de le lancer comme ceci : 
```bash
$ ./my_defender
```
<p align="center">
  <img src="https://user-images.githubusercontent.com/91092610/174766930-1627c5fe-1f1b-4679-901a-2319396aa6c7.png">
</p>

---

## Le Jeu : 

Notre jeu n'est malhreuseument pas fonctionnel mais il se trouve que nous avons la base du jeu, à savoir les monstres qui vont apparaître à droite de l'écran, et la tour à défendre sur la gauche, il nous manque malheureusement le système des tours défensives, sans quoi le jeu ne peut pas fonctionner. Nous disposons d'un menu avec trois boutons au lancement du jeu.
<p align="center">
  <img src="https://user-images.githubusercontent.com/91092610/174768544-64a5f7d3-a913-41a9-8b6d-03edcc87d886.png">
</p>
Quand à l'intérieur du jeu, nous avons créé notre propre map et nos propres sprites de player.
<p align="center">
  <img src="https://user-images.githubusercontent.com/91092610/174769258-e1b86948-4881-4cae-afa2-f36050c66b70.png">
</p>
