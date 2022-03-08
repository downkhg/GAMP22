using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Item : MonoBehaviour
{
    public enum E_ITEM_KIND { SUPER, CHERRY, GEM, BULLET }
    public E_ITEM_KIND itemKind;

    public static bool Use(GameObject obj, ItemInfo itemInfo)
    {
        switch (itemInfo.item_eff)
        {
            case E_ITEM_KIND.SUPER:
                {
                    SuperMode superMode = obj.GetComponent<SuperMode>();
                    if (superMode)
                    {
                        superMode.Active();
                        return true;
                    }
                }
                break;
            case E_ITEM_KIND.CHERRY:
                {
                    Player player = obj.GetComponent<Player>();
                    if(player)
                    {
                        player.nHP = player.nHPMax;
                        return true;
                    }
                    
                }
                break;
            case E_ITEM_KIND.GEM:
                {
                    Dynamic dynamic = obj.GetComponent<Dynamic>();

                    if (dynamic != null)
                    {
                        dynamic.Score += 100;
                        return true;
                    }
                  
                }
                break;
            case E_ITEM_KIND.BULLET:
                {
                    return true;
                }
                break;
        }
        return false;
    }
    private void OnTriggerEnter2D(Collider2D collision)
    {
        //if (Use(collision.gameObject)) 
        //    Destroy(this.gameObject);

        if(collision.tag == "Player")
        {
            Iventory iventory = collision.GetComponent<Iventory>();
            iventory.SetIventory(itemKind);
            Destroy(this.gameObject);
        }
    }
}