using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Eagle : MonoBehaviour
{
    public GameObject objTarget;
    public float Speed = 1;
    public float Site = 0.5f;
    public bool isMove = false;

    public LayerMask colLayer;

    public GameObject objResponPoint;
    public GameObject objPatrolPoint;

    public enum E_AI_STATUS { PATROL, RETRUN, TRACKING }
    public E_AI_STATUS m_eAiState;

    private void Awake()
    {
        SetStatus(m_eAiState);
    }

    void SetStatus(E_AI_STATUS state)
    {
        switch(state)
        {
            case E_AI_STATUS.PATROL:
                break;
            case E_AI_STATUS.RETRUN:
                objTarget = objResponPoint;
                break;
            case E_AI_STATUS.TRACKING:
                break;
        }
        m_eAiState = state;
    }

    private void UpdateStatus()
    {
        switch (m_eAiState)
        {
            case E_AI_STATUS.PATROL:
                MoveProcess();
                PatrolProcess();
                break;
            case E_AI_STATUS.RETRUN:
                MoveProcess();
                if (isMove == false)
                    SetStatus(E_AI_STATUS.PATROL);
                break;
            case E_AI_STATUS.TRACKING:
                MoveProcess();
                if (objTarget == null)
                    SetStatus(E_AI_STATUS.RETRUN);
                break;
        }
    }

    private void OnDrawGizmos()
    {
        Gizmos.DrawWireSphere(this.transform.position, Site);
    }

    //private void FixedUpdate()
    //{
    //    int nLayer = 1 << LayerMask.NameToLayer("Player");
    //    Vector3 vPos = this.transform.position;

    //    Collider2D[] colliders =
    //        Physics2D.OverlapCircleAll(vPos, Site, nLayer);

    //    for (int i = 0; i < colliders.Length; i++)
    //    {
    //        Collider2D collider = colliders[i];

    //        if (collider.tag == "Player")
    //            objTarget = collider.gameObject;
    //        else
    //            Debug.Log("Collder["+i+"]:" + collider.gameObject.name);      
    //    }
    //}

   

    // Start is called before the first frame update
    void Start()
    {
        //objResponPoint = GameObject.Find("EagleResponner");
    }

    private void FixedUpdate()
    {
        FindProcess();
        AttackProcess();
    }
    // Update is called once per frame
    void Update()
    {
        UpdateStatus();
        //MoveProcess();
        //ReturnProcess();
        //PatrolProcess();
    }

    void AttackProcess()
    {
        CircleCollider2D circleCollider = GetComponent<CircleCollider2D>();
        Vector2 vPos = this.transform.position;
        Vector2 vCenter = vPos + circleCollider.offset;
        int nLayer = 1 << LayerMask.NameToLayer("Player");
        Collider2D collider = 
            Physics2D.OverlapCircle(vCenter, circleCollider.radius, nLayer);

        if(collider)
        {
            SuperMode superMode = collider.GetComponent<SuperMode>();
            if (superMode != null && superMode.isUse == false)
            {
                Player me = this.GetComponent<Player>();
                Player target = collider.gameObject.GetComponent<Player>();
                me.Attack(target);
                superMode.Active();
            }
        }
    }

    void PatrolProcess()
    {
        if(isMove == false && objTarget)
        {
            if(objTarget.name == objResponPoint.name)
            {
                objTarget = objPatrolPoint;
            }
            else if(objTarget.name == objPatrolPoint.name)
            {
                objTarget = objResponPoint;
            }
        }
    }
    void ReturnProcess()
    {
        if (objTarget == null)
        {
            objTarget = objResponPoint;
        }
    }
    void FindProcess()
    {
        Vector3 vPos = this.transform.position;
        //레이어를 이용하면 레이어에 해당하는 물체만 충돌체크 가능하다.
        //int nLayer = 1 << LayerMask.NameToLayer("Player");
        //Collider2D collider = Physics2D.OverlapCircle(vPos, Site, nLayer);
        //레이어를 멤버변수로 만들어 섞을수도있다.
        Collider2D collider =
            Physics2D.OverlapCircle(vPos, Site, colLayer);

        if (collider)
        {
            objTarget = collider.gameObject;
            SetStatus(E_AI_STATUS.TRACKING);
        }
    }
    void MoveProcess()
    {
        if (objTarget)
        {
            Vector3 vTargetPos = objTarget.transform.position;
            Vector3 vPos = this.transform.position;
            Vector3 vDist = vTargetPos - vPos;
            Vector3 vDir = vDist.normalized;
            float fDist = vDist.magnitude;

            if (fDist > Time.deltaTime)
            {
                transform.position += vDir * Speed * Time.deltaTime;
                isMove = true;
            }
            else isMove = false;
        }
    }
}
