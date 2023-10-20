# Minitalk

Le but de ce projet est de coder un petit programme d'échange de données utilisant des signaux UNIX (SIGUSR1 et SIGUSR).


Il faut créer un programme de communication sous la forme d'un client et d'un serveur.

Le serveur doit d'abord être démarré. Après son lancement, il doit imprimer son PID.
Le client prend deux paramètres :
- Le PID du serveur.
- La chaîne à envoyer.
  
Le client doit envoyer la chaîne passée en paramètre au serveur. Une fois la chaîne reçue, le serveur doit l'imprimer.
Le serveur doit afficher la chaîne assez rapidement.
Votre serveur devrait pouvoir recevoir des chaînes de plusieurs clients d'affilée sans avoir besoin de redémarrer.
La communication entre votre client et votre serveur doit se faire uniquement à l'aide de signaux UNIX.
Vous ne pouvez utiliser que ces deux signaux : SIGUSR1 et SIGUSR2.

##### Bonus :

  - Le serveur accuse réception de chaque message reçu en renvoyant un signal au client.
  - Prise en charge des caractères Unicode !

## Utilisation de mon minitalk :

![Utilisation de mon minitalk](https://github.com/Maxime2i/Minitalk/assets/43725047/2cfdc38d-af39-4633-a16e-e9d1a25ab2f3)


## Comment fonctionne Minitalk ?

La communication entre le client et le serveur est réalisée à l'aide de signaux.

Le client convertit chaque caractère du message en 8 bits (1 octet) et les envoie un par un au serveur.

#### Client

   Le client lit le PID du serveur et le message à partir des arguments de ligne de commande.
   Il parcourt chaque caractère du message.
   Pour chaque caractère, il appelle une fonction, qui envoie 8 signaux au serveur.
   Cette fonction convertit le caractère en 8 bits et envoie chaque bit sous forme de signal au serveur. Il utilise SIGUSR1 pour représenter un bit 1 et SIGUSR2 pour représenter un bit 0.
   Après l'envoi de chaque bit, le client attend une courte durée à l'aide de la fonction usleep. Ce délai permet au serveur de traiter les signaux reçus.

#### Serveur

   Le serveur commence par afficher son PID sur la console.
   Il configure des gestionnaires de signaux pour les signaux SIGUSR1 et SIGUSR2 à l'aide de la fonction sigaction.
   Le serveur entre dans une boucle infinie et attend les signaux à l'aide de la fonction pause.
   Lorsqu'un signal est reçu, le gestionnaire de signal correspondant (handle_signal) est appelé.
   La fonction handle_signal extrait la valeur du bit (0 ou 1) du signal reçu et l'ajoute au caractère en cours de réception.
   Si le caractère est entièrement reçu (8 bits), il est affiché sur la console à l'aide de ft_printf. L'index des bits et le caractère actuel sont réinitialisés pour préparer le caractère suivant.
   Après avoir traité le signal reçu, le serveur renvoie un signal au client. Si le signal reçu était SIGUSR1, il envoie SIGUSR1 pour accuser réception du bit reçu. Si le signal reçu était SIGUSR2, il envoie SIGUSR2.

#### Fonctionnalités bonus

   - Les caractères Unicode comme ⚡ sont déjà pris en charge dans la partie obligatoire.
   - Le renvoi d'une confirmation de lecture peut être réalisé en utilisant la structure sigaction, qui permet d'accéder aux métadonnées sur la transmission du signal.
