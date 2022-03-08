using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[System.Serializable]
public class ItemInfo
{
    public string name;
    public string comment;
    public Item.E_ITEM_KIND item_eff;
    public string icon;
    public string effect;
    public string prefab;
    public ItemInfo(string name, string comment, Item.E_ITEM_KIND item_off, string icon, string effect, string prefab)
    {
        this.name = name;
        this.comment = comment;
        this.item_eff = item_off;
        this.icon = icon;
        this.effect = effect;
        this.prefab = prefab;
    }
}

public class ItemManager: MonoBehaviour
{
    public List<ItemInfo> Items;

    public ItemInfo GetItemInfo(int idx)
    {
        return Items[idx];
    }

    public ItemInfo GetItemInfo(Item.E_ITEM_KIND item)
    {
        return Items.Find(x => x.item_eff == item);
    }

    // Start is called before the first frame update
    void Start()
    {
        Items.Add(new ItemInfo("무적","일정시간동안 데미지를 받지않는다",Item.E_ITEM_KIND.SUPER,"yellow_gem","super_mode_eff","yellow_gem_obj"));
        Items.Add(new ItemInfo("회복", "체력을 모두 회복한다.", Item.E_ITEM_KIND.CHERRY, "cherry", "eat_eff", "recover_cherry_obj"));
        Items.Add(new ItemInfo("점수", "점수를 획득한다.", Item.E_ITEM_KIND.GEM, "white_gem", "seat_eff", "white_gem_obj"));
        Items.Add(new ItemInfo("총알", "총알을 1개씩 발사한다.", Item.E_ITEM_KIND.BULLET, "bullet", "hit_bullet", "bullet_obj"));
    }
}
