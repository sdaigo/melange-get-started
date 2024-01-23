let currency = str => {
  str |> Js.Float.toFixedWithPrecision(~digits=2);
};
