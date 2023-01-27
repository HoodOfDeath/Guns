# Realistic magazine system

1. Make FeedUnit struct (as you need to reload bullet by bullet in shotguns, it can't be called magazine)

FFeedUnit

{

    int AmmoCount
 
    EAmmoType AmmoType

    ?guid? CompatibleGun
}

2. When load gun pass struct to FeedSystem and receive one which was extracted from if. 
3. If its a shotgun return null? Make it a class or make invalid field?