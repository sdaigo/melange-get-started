type t = array(Item.t);

[@react.component]
let make = (~items: t) => {
  let total =
    items |> Js.Array.reduce((acc, order) => acc +. Item.toPrice(order), 0.);

  <table className="table">
    <tbody>
      {items
       |> Js.Array.mapi((item, index) =>
            <Item key={"item-" ++ string_of_int(index)} item />
          )
       |> React.array}
      <tr className="total">
        <td> {React.string("Total")} </td>
        <td>
          {total |> Js.Float.toFixedWithPrecision(~digits=2) |> React.string}
        </td>
      </tr>
    </tbody>
  </table>;
};
